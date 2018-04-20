#ifndef D_FakeRandomMinute_H
#define D_FakeRandomMinute_H

#include "RandomMinute.h"

void FakeRandomMinute_SetFirstAndIncrement(int seed, int increment);
int FakeRandomMinute_Get(void);
void FakeRandomMinute_Reset(void);
#endif  /* D_RandomMinute_H */
