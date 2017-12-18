#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

#include "TimeService.h"

enum
{
    TIME_UNKNOWN = -1
};

void TimeService_Create(void);
void TimeService_GetTime(Time * time);
void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);

#endif // D_FakeTimeService_H
