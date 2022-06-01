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
    ASSERT_EQ(queue_init(NULL,element_size,(uint8_t*)&buffer,buffer_size),false);
    ASSERT_EQ(queue_init(&q,element_size,NULL,buffer_size),false);
    ASSERT_EQ(queue_init(&q,0,buffer,buffer_size),false);
    ASSERT_EQ(queue_init(&q,element_size,buffer,0),false);
}

TEST(queue, QueueInitReturnTrueIfParametersAreNotNullAndNotZero)
{
    queue_t q;
    uint8_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    ASSERT_EQ(queue_init(&q,element_size,buffer,buffer_size),true);
}

TEST(queue, IfQueueHasNoElementIsEmptyReturnsTrue)
{
    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);
    ASSERT_EQ(queue_is_empty(&q),true);
}

TEST(queue, GivenAnEmptyQueueWhenEnqueueAnElementThenQueIsEmptyFunctionReturnFalse)
{
    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;

    queue_enqueue(&q,&element);
    ASSERT_EQ(queue_is_empty(&q),false);
}

TEST(queue, GIVEN_AnEmptyQueueWithSize3_WHEN_EnqueueIsCalled3Times_THEN_QueueIndexShouldBe3)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;

    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);
    ASSERT_EQ(q.index,3);
}

TEST(queue, GIVEN_AnEmptyQueueWithSize3_WHEN_EnqueueIsCalled3Times_THEN_AllTimesReturnTrue)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;

    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_enqueue(&q,&element),true);
}

TEST(queue, GIVEN_AnEmptyQueueWithSize3_WHEN_EnqueueIsCalled4Times_THEN_3TimesReturnTrueTheFourthReturnFalse)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;

    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_enqueue(&q,&element),true);
    ASSERT_EQ(queue_enqueue(&q,&element),false);
}

TEST(queue, GIVEN_AQueueWithSize1AndOneElementInTheQueue_WHEN_DequeOneElement_THEN_FunctionShouldReturnTrue)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 5;

    uint8_t dequeued;
    queue_enqueue(&q,&element);
    ASSERT_EQ(queue_dequeue(&q,&dequeued),true);
}

TEST(queue, GIVEN_AnEmptyQueueWithSize1_WHEN_DequeOneElement_THEN_FunctionShouldReturnFalse)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t dequeued;
    ASSERT_EQ(queue_dequeue(&q,&dequeued),false);
}

TEST(queue, GIVEN_AQueueWithSize3And3ElementsInserted_WHEN_Deque3Element_THEN_IndexQueueShouldBe0)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t dequeued;
    uint8_t element = 1;

    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);

    ASSERT_EQ(q.index,0);
}

TEST(queue, GIVEN_AQueueWithSize3And3ElementsInserted_WHEN_Deque2Element_THEN_IndexQueueShouldBe1)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t dequeued;
    uint8_t element = 1;

    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);

    ASSERT_EQ(q.index,1);
}

TEST(queue, GIVEN_AnEmptyQueueWithSize1_WHEN_EnqueueInteger5_THEN_DequeShouldReturn5)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 5;

    uint8_t dequeued;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,5);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueIntegers1_2_3_THEN_DequeueShouldReturn1)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;
    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    element = 3;
    queue_enqueue(&q,&element);

    uint8_t dequeued;
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,1);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueIntegers1_2_3_THEN_Dequeue3TimesShouldReturnTheSameIntegersInTheOrder1_2_3)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;
    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    element = 3;
    queue_enqueue(&q,&element);

    uint8_t dequeued;
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,1);
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,2);
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,3);
}

TEST(queue, GIVEN_AQueueWithSize1_WHEN_EnqueueInteger1AndDequeOnceTHEN_Enque2TheNextDequeShouldBe2)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 1;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;
    uint8_t dequeued;

    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);

    element = 2;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);

    ASSERT_EQ(dequeued,2);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueInteger1_2AndDequeTwiceTHEN_Enque3TheNextDequeShouldBe3)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;
    uint8_t dequeued;

    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);

    element = 3;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,3);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueInteger1_2AndDequeOnceTHEN_Enque3TheNextDequeShouldBe2)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element = 1;
    uint8_t dequeued;

    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);

    element = 3;
    queue_enqueue(&q,&element);
    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,2);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueIntegers1_2_3_DequeueOnce_EnqueInteger4THEN_TheNextDequeueShouldBe2)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element;
    uint8_t dequeued;

    element = 1;
    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    element = 3;
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);

    element = 4;
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,2);
}

TEST(queue, GIVEN_AQueueWithSize3_WHEN_EnqueueIntegers1_2_3_DequeueFourTimes_EnqueInteger4THEN_TheNextDequeueShouldBe4)
{

    queue_t q;
    uint16_t element_size = sizeof(uint8_t);
    const uint16_t buffer_size = 3;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    uint8_t element;
    uint8_t dequeued;

    element = 1;
    queue_enqueue(&q,&element);
    element = 2;
    queue_enqueue(&q,&element);
    element = 3;
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);
    queue_dequeue(&q,&dequeued);

    element = 4;
    queue_enqueue(&q,&element);

    queue_dequeue(&q,&dequeued);
    ASSERT_EQ(dequeued,4);
}

TEST(queue, GIVEN_AQueueOfTestStructWithSize3_WHEN_Enqueue3DifferentsElementsTHEN_TheNext3DequeueShouldBeTheSameInTheInsertedOrder)
{
    typedef struct
    {
        uint16_t val1;
        bool val2;
        uint8_t val3;
    }test_struct_t;

    queue_t q;
    uint16_t element_size = sizeof(test_struct_t);
    const uint16_t buffer_size = 3*element_size;
    uint8_t buffer[buffer_size];
    queue_init(&q,element_size,buffer,buffer_size);

    test_struct_t element;
    test_struct_t dequeued;

    element.val1 = 1;
    element.val2 = false;
    element.val3 = 1;
    queue_enqueue(&q,(uint8_t*)&element);
    element.val1 = 2;
    element.val2 = true;
    element.val3 = 2;
    queue_enqueue(&q,(uint8_t*)&element);
    element.val1 = 3;
    element.val2 = false;
    element.val3 = 3;
    queue_enqueue(&q,(uint8_t*)&element);

    queue_dequeue(&q,(uint8_t*)&dequeued);
    ASSERT_EQ(dequeued.val1,1);
    ASSERT_EQ(dequeued.val2,false);
    ASSERT_EQ(dequeued.val3,1);
    queue_dequeue(&q,(uint8_t*)&dequeued);
    ASSERT_EQ(dequeued.val1,2);
    ASSERT_EQ(dequeued.val2,true);
    ASSERT_EQ(dequeued.val3,2);
    queue_dequeue(&q,(uint8_t*)&dequeued);
    ASSERT_EQ(dequeued.val1,3);
    ASSERT_EQ(dequeued.val2,false);
    ASSERT_EQ(dequeued.val3,3);
}
