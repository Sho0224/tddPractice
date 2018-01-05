#ifndef D_TIME_SERVICE_H
#define D_TIME_SERVICE_H

typedef struct TIME
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

typedef void (*WakeUpCallback)(void);

void TimeService_Create(void);
void TimeService_GetTime(Time * time);
void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeUpCallback cb);

#endif // D_TIME_SERVICE_H
