#ifndef LIGHT_SCEDULER_H_
#define LIGHT_SCEDULER_H_

#include "TimeService.h"

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_Wakeup(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
#endif // LIGHT_SCEDULER_H_
