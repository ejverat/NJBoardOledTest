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
    bool (*send_cmd_fn)(uint8_t* ,uint16_t );
    bool (*send_data_fn)(uint8_t* ,uint16_t );
}display_comm_t;

typedef struct
{
    uint8_t* buffer;
    uint16_t size;
    bool isCommand;
}display_payload_t;

const display_payload_t display_comm_default = {NULL,0,false};

inline bool display_comm_send(display_comm_t* comm, display_payload_t* payload)
{
    if (comm == NULL || payload == NULL )
        return false;
    if (payload->buffer == NULL)
        return false;
    if (comm->send_cmd_fn == NULL || comm->send_data_fn == NULL)
        return false;
    if (payload->isCommand)
        return comm->send_cmd_fn(payload->buffer,payload->size);
    else
        return comm->send_data_fn(payload->buffer,payload->size);
    return true;
}

#ifdef	__cplusplus
}
#endif

#endif // DISPLAY_COMM_H
