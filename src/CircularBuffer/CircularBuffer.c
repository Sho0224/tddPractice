#include "CircularBuffer.h"
#include <stdlib.h>

static int* intBuffer;
static int pushIndex = 0;
static int popIndex = 0;

void CircularBuffer_Create(int size)
{
    intBuffer = malloc(size);
}

void CircularBuffer_push(int input)
{
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
