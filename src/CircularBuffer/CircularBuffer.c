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
        pushIndex = 0;
    }
    intBuffer[pushIndex] = input;
    pushIndex++;
}

int CircularBuffer_pop()
{
    if(pushIndex <= popIndex)
    {
        RUNTIME_ERROR("CircularBuffer Driver:No data area access", -1);
        return 0;
    }
    int tmp = intBuffer[popIndex];
    popIndex++;
    if(popIndex >= bufferSize)
    {
        popIndex = 0;
    }
    return tmp;
}

void CircularBuffer_Destroy()
{
    free(intBuffer);
    popIndex = 0;
    pushIndex = 0;
}
