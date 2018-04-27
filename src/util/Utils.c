#include "Utils.h"
#include <stdio.h>

static int FormatOutput_Impl(const char * format, ...)
{
    /* snip */
}

int (*FormatOutput)(const char * format, ...) = FormatOutput_Impl;
