#include "uvcvideo.h"

#define V4L2_CID_PAN_RELATIVE_LOGITECH   0x0A046D01
#define V4L2_CID_TILT_RELATIVE_LOGITECH  0x0A046D02
#define V4L2_CID_PANTILT_RESET_LOGITECH  0x0A046D03
#define V4L2_CID_FOCUS_LOGITECH          0x0A046D04
#define V4L2_CID_LED1_MODE_LOGITECH      0x0A046D05
#define V4L2_CID_LED1_FREQUENCY_LOGITECH 0x0A046D06

#define UVC_GUID_LOGITECH_MOTOR_CONTROL {0x82, 0x06, 0x61, 0x63, 0x70, 0x50, 0xab, 0x49, 0xb8, 0xcc, 0xb3, 0x85, 0x5e, 0x8d, 0x22, 0x56}
#define UVC_GUID_LOGITECH_USER_HW_CONTROL {0x82, 0x06, 0x61, 0x63, 0x70, 0x50, 0xab, 0x49, 0xb8, 0xcc, 0xb3, 0x85, 0x5e, 0x8d, 0x22, 0x1f}

#define XU_HW_CONTROL_LED1               1
#define XU_MOTORCONTROL_PANTILT_RELATIVE 1
#define XU_MOTORCONTROL_PANTILT_RESET    2
#define XU_MOTORCONTROL_FOCUS            3

#define ONE_DEGREE (64);
#define MAX_PAN  (70*64)
#define MIN_PAN  (-70*64)
#define MAX_TILT (30*64)
#define MIN_TILT (-30*64)
#define MIN_RES  (64*5)

void initDynCtrls(int dev);
int uvcPanTilt(int dev, int pan, int tilt, int reset);
