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

static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

static int scheduleEvent(int id, Day day, int minuteOfDay, int event);
static void processEventDueNow(Time* time, ScheduledLightEvent* LightEvent);
static void operateLight(ScheduledLightEvent* LightEvent);
static int DoesLightRespondToday(Time *time, int reactionDay);

void LightScheduler_Create(void)
{
    int i;

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
}

static int scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    int i;

    if(id < 0 || id > 31)
    {
        return LS_ID_OUT_OF_BOUNDS;
    }

    for(i = 0; i < MAX_EVENTS; i++)
    {
        if(scheduledEvents[i].id == UNUSED)
        {
            scheduledEvents[i].id = id;
            scheduledEvents[i].minuteOfDay = minuteOfDay;
            scheduledEvents[i].event = event;
            scheduledEvents[i].day = day;
            return LS_OK;
        }
    }
    return LS_TOO_MANY_EVENTS;
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

int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, LIGHT_ON);
}

int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, LIGHT_OFF);
}

void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
    int i;

    for (i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == id
         && scheduledEvents[i].day == day
         && scheduledEvents[i].minuteOfDay == minuteOfDay)
         {
             scheduledEvents[i].id = UNUSED;
         }
    }
}

