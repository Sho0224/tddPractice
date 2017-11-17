#include "CircularBuffer.h"
#include "RuntimeError.h"
#include <stdlib.h>

static int* intBuffer;
static int bufferSize = 0;
static int pushIndex = 0;
static int popIndex = 0;

void CircularBuffer_Create(int size)
{
    bufferSize = size;
    intBuffer = (int *)malloc(size*sizeof(int));
}

void CircularBuffer_push(int input)
{
    if(bufferSize <= pushIndex)
    {
        RUNTIME_ERROR("CircularBuffer Driver:Buffer size over Push", -1);
        return;
    }
    intBuffer[pushIndex] = input;
    pushIndex++;
}

int CircularBuffer_pop()
{
    int tmp = intBuffer[popIndex];
    popIndex++;
    return tmp;
}

void CircularBuffer_Destroy()
{
    free(intBuffer);
}
