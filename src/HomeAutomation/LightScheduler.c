#include "LightScheduler.h"
#include "LightController.h"
#include "TimeService.h"
#include <stdbool.h>

enum 
{
    UNUSED = -1,
    MAX_EVENTS = 128 
};

typedef struct
{
    int id;
    int minuteOfDay;
    int event;
    int day;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;
static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

static void scheduleEvent(int id, Day day, int minuteOfDay, int event);
static void processEventDueNow(Time* time, ScheduledLightEvent* LightEvent);
static void operateLight(ScheduledLightEvent* LightEvent);
static int DoesLightRespondToday(Time *time, int reactionDay);

void LightScheduler_Create(void)
{
    int i;

    scheduledEvent.id = UNUSED;

    for(i = 0; i < MAX_EVENTS; i++)
    {
        scheduledEvents[i].id = UNUSED;
    }
    TimeService_SetPeriodicAlarmInSeconds(60, LightScheduler_Wakeup);
}

void LightScheduler_Destroy(void)
{
    TimeService_CancelPeriodicAlarmInSeconds(60, LightScheduler_Wakeup);
}

void LightScheduler_Wakeup(void)
{
    int i;
    Time time;
    TimeService_GetTime(&time);

    for(i = 0; i < MAX_EVENTS; i++)
    {
        processEventDueNow(&time, &scheduledEvents[i]);
    }

    processEventDueNow(&time, &scheduledEvent);
}

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    int i;

    for(i = 0; i < MAX_EVENTS; i++)
    {
        if(scheduledEvents[i].id == UNUSED)
        {
            scheduledEvents[i].id = id;
            scheduledEvents[i].minuteOfDay = minuteOfDay;
            scheduledEvents[i].event = event;
            scheduledEvents[i].day = day;
            break;
        }
    }

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
