#include "unity_fixture.h"
#include <stdint.h>
#include "LedDriver.h"
TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
}

TEST_TEAR_DOWN(LedDriver)
{
}

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualleds = 0xffff;
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
}

TEST(LedDriver, TurnOnLedOne)
{
    uint16_t virtualleds;
    LedDriver_Create(&virtualleds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualleds);
}
