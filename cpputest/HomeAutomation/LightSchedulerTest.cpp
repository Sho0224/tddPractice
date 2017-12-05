// TEST(LightSceduler,SceduleOnEverydayNotTimeYet)
// {
//     LightSceduler_ScheduleTurnOn(3, EVERYDAY, 1200);
//     FakeTimeService_SetDay(MONDAY);
//     FakeTimeService_SetMinute(1199);
//     
//     LightSceduler_Wakeup();
// 
//     LONGS_EQUAL(LIGHT_ID_UNKKNOWN, LightControllerSpy_GetLastId());
//     LONGS_EQUAL(LIGHT_STATE_UNKKNOWN, LightControllerSpy_LastState());
// }

// TEST(LightSceduler, NoChangeToLightsDuringInitialization)
// {
//     LONGS_EQUAL(LIGHT_ID_UNKKNOWN, LightControllerSpy_GetLastId());
//     LONGS_EQUAL(LIGHT_STATE_UNKKNOWN, LightControllerSpy_LastState());
// }
