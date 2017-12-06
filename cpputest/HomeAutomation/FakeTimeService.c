#include "FakeTimeService.h"

void TimeService_GetTime(Time * time)
{
    time->minuteOfDay = TIME_UNKNOWN;
    time->dayOfWeek = TIME_UNKNOWN;
}
