#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

#include "TimeService.h"

enum
{
    TIME_UNKNOWN = -1
};

void TimeService_GetTime(Time * time);

#endif // D_FakeTimeService_H
