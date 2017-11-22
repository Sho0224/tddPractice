#include "CppuTest/TestHarness.h"

extern "C"
{
#include "LightControllerSpy.h"
}

TEST_GROUP(LightControllerSpy)
{
    void setup()
    {
        LightController_Create();
    }

    void teardown()
    {
        LightController_Destroy();
    }
};

TEST(LightControllerSpy, Create)
{
    LONGS_EQUAL(LIGHT_ID_UNKKNOWN, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKKNOWN, LightControllerSpy_LastState());
}
