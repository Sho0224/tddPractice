#include "unity_fixture.h"
#include <stdint.h>
#include "LedDriver.h"
TEST_GROUP(LedDriver);

static uint16_t virtualleds;
TEST_SETUP(LedDriver)
{
    LedDriver_Create(&virtualleds);
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
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualleds);
}

TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
}
