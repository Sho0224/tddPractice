#include "CircularBuffer.h"

static int intBuffer[256];
static int pushIndex = 0;
static int popIndex = 0;

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
