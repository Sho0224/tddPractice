#include "unity_fixture.h"
#include "CircularBuffer.h"
#include "RuntimeErrorStub.h"

TEST_GROUP(CircularBuffer);

static int bufferSize = 256;

TEST_SETUP(CircularBuffer)
{
    CircularBuffer_Create(bufferSize);
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

TEST(CircularBuffer, OutOfBoundsBufferSizeOver)
{
    int i = 0;
    for(i = 0; i < bufferSize; i++)
    {
       CircularBuffer_push(i);
    } 
    TEST_ASSERT_EQUAL_STRING("CircularBuffer Driver:Buffer size over Push",
        RuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

// TODO $B%]%C%W$7$J$$$G%W%C%7%e$9$k(B
