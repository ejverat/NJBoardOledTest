#ifndef GDISPLAY_DRIVER_H
#define GDISPLAY_DRIVER_H
#ifdef	__cplusplus
extern "C" {
#endif

#include "display_comm.h"
#include "timer.h"

typedef struct
{
    display_comm_t* comm;
    waiter_t* timer;
    bool (*init_fn)();
    bool (*send_cmd_fn)(uint8_t,uint8_t*); //send command and array of parameters
    bool (*send_data_fn)(uint8_t*,uint16_t); //send array of bytes with a size
}gdisplay_driver_t;

#ifdef	__cplusplus
}
#endif
#endif // GDISPLAY_DRIVER_H
