#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

#include "TimeService.h"

enum
{
    TIME_UNKNOWN = -1
};

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);

#endif // D_FakeTimeService_H
