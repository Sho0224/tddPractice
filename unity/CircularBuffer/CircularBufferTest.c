#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
    CircularBuffer_Create(256);
}

TEST_TEAR_DOWN(CircularBuffer)
{
    CircularBuffer_Destroy();
}

TEST(CircularBuffer, OneInputOneOutput)
{
    CircularBuffer_push(1);
    TEST_ASSERT_EQUAL(1,CircularBuffer_pop());
}

TEST(CircularBuffer, TwoInputTwoOutput)
{
    CircularBuffer_push(1);
    CircularBuffer_push(2);
    TEST_ASSERT_EQUAL(1,CircularBuffer_pop());
    TEST_ASSERT_EQUAL(2,CircularBuffer_pop());
}
