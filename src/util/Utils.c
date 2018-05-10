#include "Utils.h"
#include <stdio.h>

static int FormatOutput_Impl(const char * format, ...)
{
    /* snip */
    return 0;
}

int (*FormatOutput)(const char * format, ...) = FormatOutput_Impl;
