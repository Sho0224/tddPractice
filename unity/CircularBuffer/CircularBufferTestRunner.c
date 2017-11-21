#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, OneInputOneOutput);
    RUN_TEST_CASE(CircularBuffer, TwoInputTwoOutput);
    RUN_TEST_CASE(CircularBuffer, OutOfBoundsNoPushPop);
    RUN_TEST_CASE(CircularBuffer, Circular);
}
