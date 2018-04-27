#include "FormatOutputSpy.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
static char * buffer = 0;
static size_t buffer_size = 0;
static size_t buffer_offset = 0;

int FormatOutputSpy(const char * format, ...)
{
    va_list arg;
    va_start(arg, format);
    buffer_offset += vsnprintf(buffer + buffer_offset, buffer_size - buffer_offset, format, arg);
    va_end(arg);
    return -1;
}

void FormatOutputSpy_Create(int size)
{
    buffer_size = size+1;
    buffer_offset = 0;
    buffer = (char *)calloc(buffer_size + 1, sizeof(char));
    buffer[buffer_size] = '\0'; 
}

void FormatOutputSpy_Destroy(void)
{
    free(buffer);
}

const char * FormatOutputSpy_GetOutput(void)
{
   return buffer;
}
