#ifndef D_TIME_SERVICE_H
#define D_TIME_SERVICE_H

typedef struct TIME
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_GetTime(Time * time);

#endif // D_TIME_SERVICE_H
