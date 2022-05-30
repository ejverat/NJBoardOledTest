#include "queue.h"

bool queue_init(queue_t* q, uint8_t element_size, void* buffer_ptr,uint16_t buffer_size)
{
    if(q == NULL || buffer_ptr == NULL || element_size == 0 || buffer_size == 0)
        return false;
    q->index = 0;
    return true;
}

bool queue_is_empty(queue_t* q)
{
    if (q->index == 1)
        return false;
    return true;
}

bool queue_enqueue(queue_t* q, void* element_ptr)
{
    q->index = 1;
    return true;
}
