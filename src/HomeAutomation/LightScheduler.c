#include "LightScheduler.h"
#include "LightController.h"
#include "TimeService.h"

enum 
{
    UNUSED = -1
};

typedef struct
{
    int id;
    int minuteOfDay;
    LIGHT_CONTROLLER_EVENT event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{

}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);
    if(scheduledEvent.id == UNUSED)
        return;
    if(time.minuteOfDay != scheduledEvent.minuteOfDay)
        return;

    if(scheduledEvent.event == LIGHT_ON)
    {
        LightController_On(scheduledEvent.id);
    }else if(scheduledEvent.event == LIGHT_OFF)
    {
        LightController_Off(scheduledEvent.id);
    }
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = LIGHT_ON;
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = LIGHT_OFF;
}
