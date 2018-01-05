#include "LightScheduler.h"
#include "LightController.h"
#include "TimeService.h"
#include <stdbool.h>

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
static int DoesLightRespondToday(Time *time, int reactionDay);

void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
    TimeService_SetPeriodicAlarmInSeconds(60, LightScheduler_Wakeup);
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
    if(!DoesLightRespondToday(time, lightEvent->day))
        return;
    if(time->minuteOfDay != lightEvent->minuteOfDay)
        return;
    operateLight(lightEvent);
}

static int DoesLightRespondToday(Time *time, int reactionDay)
{
    int today = time->dayOfWeek;

    if(reactionDay == EVERYDAY)
        return true;
    if(reactionDay == today)
        return true;
    if(reactionDay == WEEKEND && (today == SATURDAY || today == SUNDAY))
        return true;
    if(reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY)
        return true;
    return false;
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
