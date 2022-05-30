#ifndef QUEUE_H
#define QUEUE_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    void* buffer_ptr;
    uint8_t element_size;
    uint16_t buffer_size;
    uint16_t index;
}queue_t;

bool queue_init(queue_t* q, uint8_t element_size, void* buffer_ptr,uint16_t buffer_size);

bool queue_is_empty(queue_t* q);

bool queue_enqueue(queue_t* q,void* element_ptr);

#ifdef	__cplusplus
}
#endif
#endif // QUEUE_H
