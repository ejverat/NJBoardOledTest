#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "queue.h"
#include "queue.c"

#include <cstdint>

using namespace testing;


TEST(queue, QueueInitReturnFalseIfSomeParameterIsNullOrZero)
{
    queue_t q;
    uint8_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    ASSERT_EQ(queue_init(NULL,element_size,&buffer,buffer_size),false);
    ASSERT_EQ(queue_init(&q,element_size,NULL,buffer_size),false);
    ASSERT_EQ(queue_init(&q,0,&buffer,buffer_size),false);
    ASSERT_EQ(queue_init(&q,element_size,&buffer,0),false);
}

TEST(queue, QueueInitReturnTrueIfParametersAreNotNullAndNotZero)
{
    queue_t q;
    uint8_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    ASSERT_EQ(queue_init(&q,element_size,&buffer,buffer_size),true);
}

TEST(queue, IfQueueHasNoElementIsEmptyReturnsTrue)
{
    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,&buffer,buffer_size);
    ASSERT_EQ(queue_is_empty(&q),true);
}

TEST(queue, EnqueueFunctionReturnTrueIfElementsInQueueAreLessOrEqualThanBufferSizeAndIsEmptyReturnFalse)
{
    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,&buffer,buffer_size);

    uint8_t element = 1;

    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_is_empty(&q),false);
}

//after enqueue is_empty return false
