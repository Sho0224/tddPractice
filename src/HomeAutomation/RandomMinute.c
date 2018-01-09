#include "RandomMinute.h"
#include <stdlib.h>

static int bound = 0;

void RandomMinute_Create(int b)
{
    bound = b;
}

int RandomMinute_Get()
{
    return bound - rand() % (bound * 2 + 1);
}
