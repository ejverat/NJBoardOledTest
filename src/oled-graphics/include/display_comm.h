#ifndef DISPLAY_COMM_H
#define DISPLAY_COMM_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct
{
    bool (*init_fn)();
    void (*enable_fn)();
    void (*disable_fn)();
    void (*start_reset_fn)();
    void (*end_reset_fn)();
    void (*enable_cmd_fn)();
    void (*disable_cmd_fn)();
    void (*enable_data_fn)();
    void (*disable_data_fn)();
    bool (*send_byte_fn)(uint8_t);
}display_comm_t;

#ifdef	__cplusplus
}
#endif

#endif // DISPLAY_COMM_H
