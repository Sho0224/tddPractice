#include "CppUTest/TestHarness.h"

extern "C"
{
#include <stdio.h>
#include <string.h>
#include "RandomMinute.h"
}

enum { BOUND=30 };

TEST_GROUP(RandomMinute)
{
    int minute;
    void setup()
    {
        RandomMinute_Create(BOUND);
        srand(1);
    }

    void AssertMinuteIsInRange()
    {
        if(minute < -BOUND || minute > BOUND)
        {
            printf("bad minute value: %d\n", minute);
            FAIL("Minute out of range");
        }
    }
};

TEST(RandomMinute, GetIsInRange)
{
    for (int i = 0; i < 100; i++)
    {
        minute = RandomMinute_Get();
        AssertMinuteIsInRange();
    }
}
