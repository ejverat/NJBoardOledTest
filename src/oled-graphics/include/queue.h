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
    uint8_t* buffer_ptr;
    uint8_t element_size;
    uint16_t buffer_size;
    uint16_t index;
    uint16_t index_of_next;
    uint16_t index_of_last;
}queue_t;

bool queue_init(queue_t* q, uint8_t element_size, uint8_t* buffer_ptr,uint16_t buffer_size);

bool queue_is_empty(queue_t* q);

bool queue_enqueue(queue_t* q,uint8_t* element_ptr);

bool queue_dequeue(queue_t* q,uint8_t* element_ptr);

#ifdef	__cplusplus
}
#endif
#endif // QUEUE_H
