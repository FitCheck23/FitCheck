#define IO_BUFFER 256
#define BUFFER_SIZE 1024

#define BOUNDARY "boundarydonotcross"

#define MAX_FRAME_SIZE (256*1024)
#define TEN_K (10*1024)

#define STD_HEADER "Connection: close\r\n" \
    "Server: streamer/0.2\r\n" \
    "Cache-Control: no-store, no-cache, must-revalidate, pre-check=0, post-check=0, max-age=0\r\n" \
    "Pragma: no-cache\r\n" \
    "Expires: Mon, 3 Jan 2000 12:34:56 GMT\r\n"

#define MAX_SD_LEN 50

static const struct {
    const char *dot_extension;
    const char *mimetype;
} mimetypes[] = {
    { ".html", "text/html" },
    { ".htm",  "text/html" },
    { ".css",  "text/css" },
    { ".js",   "text/javascript" },
    { ".txt",  "text/plain" },
    { ".jpg",  "image/jpeg" },
    { ".jpeg", "image/jpeg" },
    { ".png",  "image/png"},
    { ".gif",  "image/gif" },
    { ".ico",  "image/x-icon" },
    { ".swf",  "application/x-shockwave-flash" },
    { ".cab",  "application/x-shockwave-flash" },
    { ".jar",  "application/java-archive" },
    { ".json", "application/json" }
};

/* the webserver determines between these values for an answer */
typedef enum {
    A_UNKNOWN,
    A_SNAPSHOT,
    A_SNAPSHOT_WXP,
    A_STREAM,
    A_STREAM_WXP,
    A_COMMAND,
    A_FILE,
    A_CGI,
    A_TAKE,
    A_INPUT_JSON,
    A_OUTPUT_JSON,
    A_PROGRAM_JSON,
    #ifdef MANAGMENT
    A_CLIENTS_JSON
    #endif
} answer_t;

/*
 * the client sends information with each request
 * this structure is used to store the important parts
 */
typedef struct {
    answer_t type;
    char *parameter;
    char *client;
    char *credentials;
    char *query_string;
} request;

/* the iobuffer structure is used to read from the HTTP-client */
typedef struct {
    int level;              /* how full is the buffer */
    char buffer[IO_BUFFER]; /* the data */
} iobuffer;

/* store configuration for each server instance */
typedef struct {
    int port;
    char *hostname;
    char *credentials;
    char *www_folder;
    char nocommands;
} config;

/* context of each server thread */
typedef struct {
    int sd[MAX_SD_LEN];
    int sd_len;
    int id;
    globals *pglobal;
    pthread_t threadID;

    config conf;
} context;


#if defined(MANAGMENT)
/*
 * this struct is used to hold information from the clients address, and last picture take time
 */
typedef struct _client_info {
    struct _client_info *next;
    char *address;
    struct timeval last_take_time;
} client_info;

struct {
    client_info **infos;
    unsigned int client_count;
    pthread_mutex_t mutex;
} client_infos;

#endif

/*
 * this struct is just defined to allow passing all necessary details to a worker thread
 * "cfd" is for connected/accepted filedescriptor
 */
typedef struct {
    context *pc;
    int fd;
    #ifdef MANAGMENT
    client_info *client;
    #endif
} cfd;



/* prototypes */
void *server_thread(void *arg);
void send_error(int fd, int which, char *message);
void send_output_JSON(int fd, int plugin_number);
void send_input_JSON(int fd, int plugin_number);
void send_program_JSON(int fd);
void check_JSON_string(char *source, char *destination);

#ifdef MANAGMENT
client_info *add_client(char *address);
int check_client_status(client_info *client);
void update_client_timestamp(client_info *client);
void send_clients_JSON(int fd);
#endif









