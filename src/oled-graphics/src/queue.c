#include "queue.h"
#include <string.h>

bool queue_init(queue_t* q, uint8_t element_size, uint8_t* buffer_ptr,uint16_t buffer_size)
{
    if(q == NULL || buffer_ptr == NULL || element_size == 0 || buffer_size == 0)
        return false;
    q->index = 0;
    q->index_of_next = 0;
    q->index_of_last = 0;
    q->element_size = element_size;
    q->buffer_ptr = buffer_ptr;
    q->buffer_size = buffer_size;
    return true;
}

bool queue_is_empty(queue_t* q)
{
    if (q->index > 0)
        return false;
    return true;
}

bool queue_enqueue(queue_t* q, uint8_t* element_ptr)
{
    if (q->index * q->element_size == q->element_size * q->buffer_size)
        return false;
    memcpy(q->buffer_ptr+(q->index_of_last)*q->element_size,element_ptr,q->element_size);
    q->index++;
    q->index_of_last++;
    if (q->index_of_last == q->buffer_size)
        q->index_of_last = 0;
    return true;
}

bool queue_dequeue(queue_t* q, uint8_t* element_ptr)
{
    if (q->index == 0)
        return false;
    memcpy(element_ptr, q->buffer_ptr + (q->index_of_next*q->element_size),q->element_size);
    q->index--;

    q->index_of_next++;

    if(q->index_of_next == q->buffer_size)
        q->index_of_next = 0;
    return true;
}
