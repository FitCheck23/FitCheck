#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <pthread.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <syslog.h>
#include <linux/types.h>    
#include <linux/videodev2.h>

#include "utils.h"
#include "mjpg_streamer.h"

/* globals */
static globals global;

static void help(char *progname)
{
    fprintf(stderr, "-----------------------------------------------------------------------\n");
    fprintf(stderr, "Usage: %s\n" \
            "  -i | --input \"<input-plugin.so> [parameters]\"\n" \
            "  -o | --output \"<output-plugin.so> [parameters]\"\n" \
            " [-h | --help ]........: display this help\n" \
            " [-v | --version ].....: display version information\n" \
            " [-b | --background]...: fork to the background, daemon mode\n", progname);
    fprintf(stderr, "-----------------------------------------------------------------------\n");
    fprintf(stderr, "Example #1:\n" \
            " To open an UVC webcam \"/dev/video1\" and stream it via HTTP:\n" \
            "  %s -i \"input_uvc.so -d /dev/video1\" -o \"output_http.so\"\n", progname);
    fprintf(stderr, "-----------------------------------------------------------------------\n");
    fprintf(stderr, "Example #2:\n" \
            " To open an UVC webcam and stream via HTTP port 8090:\n" \
            "  %s -i \"input_uvc.so\" -o \"output_http.so -p 8090\"\n", progname);
    fprintf(stderr, "-----------------------------------------------------------------------\n");
    fprintf(stderr, "Example #3:\n" \
            " To get help for a certain input plugin:\n" \
            "  %s -i \"input_uvc.so --help\"\n", progname);
    fprintf(stderr, "-----------------------------------------------------------------------\n");
    fprintf(stderr, "In case the modules (=plugins) can not be found:\n" \
            " * Set the default search path for the modules with:\n" \
            "   export LD_LIBRARY_PATH=/path/to/plugins,\n" \
            " * or put the plugins into the \"/lib/\" or \"/usr/lib\" folder,\n" \
            " * or instead of just providing the plugin file name, use a complete\n" \
            "   path and filename:\n" \
            "   %s -i \"/path/to/modules/input_uvc.so\"\n", progname);
    fprintf(stderr, "-----------------------------------------------------------------------\n");
}

static void signal_handler(int sig)
{
    int i;

    /* signal "stop" to threads */
    LOG("setting signal to stop\n");
    global.stop = 1;
    usleep(1000 * 1000);

    /* clean up threads */
    LOG("force cancellation of threads and cleanup resources\n");
    for(i = 0; i < global.incnt; i++) {
        global.in[i].stop(i);
    }

    for(i = 0; i < global.outcnt; i++) {
        global.out[i].stop(global.out[i].param.id);
        pthread_cond_destroy(&global.in[i].db_update);
        pthread_mutex_destroy(&global.in[i].db);
    }
    usleep(1000 * 1000);

    for(i = 0; i < global.incnt; i++) {
        dlclose(global.in[i].handle);
    }

    for(i = 0; i < global.outcnt; i++) {
        int j, skip = 0;
        DBG("about to decrement usage counter for handle of %s, id #%02d, handle: %p\n", \
            global.out[i].plugin, global.out[i].param.id, global.out[i].handle);

        for(j=i+1; j<global.outcnt; j++) {
          if ( global.out[i].handle == global.out[j].handle ) {
            DBG("handles are pointing to the same destination (%p == %p)\n", global.out[i].handle, global.out[j].handle);
            skip = 1;
          }
        }
        if ( skip ) {
          continue;
        }

        DBG("closing handle %p\n", global.out[i].handle);

        dlclose(global.out[i].handle);
    }
    DBG("all plugin handles closed\n");

    LOG("done\n");

    closelog();
    exit(0);
    return;
}

static int split_parameters(char *parameter_string, int *argc, char **argv)
{
    int count = 1;
    argv[0] = NULL; // the plugin may set it to 'INPUT_PLUGIN_NAME'
    if(parameter_string != NULL && strlen(parameter_string) != 0) {
        char *arg = NULL, *saveptr = NULL, *token = NULL;

        arg = strdup(parameter_string);

        if(strchr(arg, ' ') != NULL) {
            token = strtok_r(arg, " ", &saveptr);
            if(token != NULL) {
                argv[count] = strdup(token);
                count++;
                while((token = strtok_r(NULL, " ", &saveptr)) != NULL) {
                    argv[count] = strdup(token);
                    count++;
                    if(count >= MAX_PLUGIN_ARGUMENTS) {
                        IPRINT("ERROR: too many arguments to input plugin\n");
                        return 0;
                    }
                }
            }
        }
        free(arg);
    }
    *argc = count;
    return 1;
}


int main(int argc, char *argv[])
{
    char *input[MAX_INPUT_PLUGINS];
    char *output[MAX_OUTPUT_PLUGINS];
    int daemon = 0, i, j;
    size_t tmp = 0;

    output[0] = "output_http.so --port 8080";
    global.outcnt = 0;
    global.incnt = 0;

    /* parameter parsing */
    while(1) {
        int c = 0;
        static struct option long_options[] = {
            {"help", no_argument, NULL, 'h'},
            {"input", required_argument, NULL, 'i'},
            {"output", required_argument, NULL, 'o'},
            {"version", no_argument, NULL, 'v'},
            {"background", no_argument, NULL, 'b'},
            {NULL, 0, NULL, 0}
        };

        c = getopt_long(argc, argv, "hi:o:vb", long_options, NULL);

        if(c == -1) break;

        switch(c) {
        case 'i':
            input[global.incnt++] = strdup(optarg);
            break;

        case 'o':
            output[global.outcnt++] = strdup(optarg);
            break;

        case 'v':
            printf("MJPG Streamer Version: %s\n",
#ifdef GIT_HASH
            GIT_HASH
#else
            SOURCE_VERSION
#endif
            );
            return 0;
            break;

        case 'b':
            daemon = 1;
            break;

        case 'h':
        default:
            help(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    openlog("streamer ", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "starting application");

    if(daemon) {
        LOG("enabling daemon mode");
        daemon_mode();
    }

    signal(SIGPIPE, SIG_IGN);

    if(signal(SIGINT, signal_handler) == SIG_ERR) {
        LOG("could not register signal handler\n");
        closelog();
        exit(EXIT_FAILURE);
    }

#ifdef GIT_HASH
    LOG("MJPG Streamer Version: git rev: %s\n", GIT_HASH);
#else
    LOG("MJPG Streamer Version.: %s\n", SOURCE_VERSION);
#endif

    if(global.outcnt == 0) {
        global.outcnt = 1;
    }

    /* open input plugin */
    for(i = 0; i < global.incnt; i++) {
        if(pthread_mutex_init(&global.in[i].db, NULL) != 0) {
            LOG("could not initialize mutex variable\n");
            closelog();
            exit(EXIT_FAILURE);
        }
        if(pthread_cond_init(&global.in[i].db_update, NULL) != 0) {
            LOG("could not initialize condition variable\n");
            closelog();
            exit(EXIT_FAILURE);
        }

        tmp = (size_t)(strchr(input[i], ' ') - input[i]);
        global.in[i].stop      = 0;
        global.in[i].context   = NULL;
        global.in[i].buf       = NULL;
        global.in[i].size      = 0;
        global.in[i].plugin = (tmp > 0) ? strndup(input[i], tmp) : strdup(input[i]);
        global.in[i].handle = dlopen(global.in[i].plugin, RTLD_LAZY);
        if(!global.in[i].handle) {
            LOG("ERROR: could not find input plugin\n");
            LOG("       Perhaps you want to adjust the search path with:\n");
            LOG("       # export LD_LIBRARY_PATH=/path/to/plugin/folder\n");
            LOG("       dlopen: %s\n", dlerror());
            closelog();
            exit(EXIT_FAILURE);
        }
        global.in[i].init = dlsym(global.in[i].handle, "input_init");
        if(global.in[i].init == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        global.in[i].stop = dlsym(global.in[i].handle, "input_stop");
        if(global.in[i].stop == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        global.in[i].run = dlsym(global.in[i].handle, "input_run");
        if(global.in[i].run == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        global.in[i].cmd = dlsym(global.in[i].handle, "input_cmd");

        global.in[i].param.parameters = strchr(input[i], ' ');

        for (j = 0; j<MAX_PLUGIN_ARGUMENTS; j++) {
            global.in[i].param.argv[j] = NULL;
        }

        split_parameters(global.in[i].param.parameters, &global.in[i].param.argc, global.in[i].param.argv);
        global.in[i].param.global = &global;
        global.in[i].param.id = i;

        if(global.in[i].init(&global.in[i].param, i)) {
            LOG("input_init() return value signals to exit\n");
            closelog();
            exit(0);
        }
    }

    /* open output plugin */
    for(i = 0; i < global.outcnt; i++) {
        tmp = (size_t)(strchr(output[i], ' ') - output[i]);
        global.out[i].plugin = (tmp > 0) ? strndup(output[i], tmp) : strdup(output[i]);
        global.out[i].handle = dlopen(global.out[i].plugin, RTLD_LAZY);
        if(!global.out[i].handle) {
            LOG("ERROR: could not find output plugin %s\n", global.out[i].plugin);
            LOG("       Perhaps you want to adjust the search path with:\n");
            LOG("       # export LD_LIBRARY_PATH=/path/to/plugin/folder\n");
            LOG("       dlopen: %s\n", dlerror());
            closelog();
            exit(EXIT_FAILURE);
        }
        global.out[i].init = dlsym(global.out[i].handle, "output_init");
        if(global.out[i].init == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        global.out[i].stop = dlsym(global.out[i].handle, "output_stop");
        if(global.out[i].stop == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        global.out[i].run = dlsym(global.out[i].handle, "output_run");
        if(global.out[i].run == NULL) {
            LOG("%s\n", dlerror());
            exit(EXIT_FAILURE);
        }

        /* try to find optional command */
        global.out[i].cmd = dlsym(global.out[i].handle, "output_cmd");

        global.out[i].param.parameters = strchr(output[i], ' ');

        for (j = 0; j<MAX_PLUGIN_ARGUMENTS; j++) {
            global.out[i].param.argv[j] = NULL;
        }
        split_parameters(global.out[i].param.parameters, &global.out[i].param.argc, global.out[i].param.argv);

        global.out[i].param.global = &global;
        global.out[i].param.id = i;
        if(global.out[i].init(&global.out[i].param, i)) {
            LOG("output_init() return value signals to exit\n");
            closelog();
            exit(EXIT_FAILURE);
        }
    }

    /* start to read the input, push pictures into global buffer */
    DBG("starting %d input plugin\n", global.incnt);
    for(i = 0; i < global.incnt; i++) {
        syslog(LOG_INFO, "starting input plugin %s", global.in[i].plugin);
        if(global.in[i].run(i)) {
            LOG("can not run input plugin %d: %s\n", i, global.in[i].plugin);
            closelog();
            return 1;
        }
    }

    DBG("starting %d output plugin(s)\n", global.outcnt);
    for(i = 0; i < global.outcnt; i++) {
        syslog(LOG_INFO, "starting output plugin: %s (ID: %02d)", global.out[i].plugin, global.out[i].param.id);
        global.out[i].run(global.out[i].param.id);
    }

    /* wait for signals */
    pause();

    return 0;
}
