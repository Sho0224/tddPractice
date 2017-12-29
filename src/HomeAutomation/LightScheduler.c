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
    int event;
    int day;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;
static void scheduleEvent(int id, Day day, int minuteOfDay, int event);
static void processEventDueNow(Time* time, ScheduledLightEvent* LightEvent);
static void operateLight(ScheduledLightEvent* LightEvent);

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

    processEventDueNow(&time, &scheduledEvent);
}

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = event;
    scheduledEvent.day = day;
}

static void processEventDueNow(Time* time, ScheduledLightEvent* lightEvent)
{
    if(lightEvent->id == UNUSED)
        return;
    if(lightEvent->day != EVERYDAY && lightEvent->day != WEEKEND && lightEvent->day != time->dayOfWeek)
        return;
    if(lightEvent->day == WEEKEND && !(time->dayOfWeek == SATURDAY || time->dayOfWeek == SUNDAY))
        return;
    if(time->minuteOfDay != lightEvent->minuteOfDay)
        return;
    operateLight(lightEvent);
}

static void operateLight(ScheduledLightEvent* lightEvent)
{
    if(lightEvent->event == LIGHT_ON)
    {
        LightController_On(lightEvent->id);
    }else if(lightEvent->event == LIGHT_OFF)
    {
        LightController_Off(lightEvent->id);
    }
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, LIGHT_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, LIGHT_OFF);
}
