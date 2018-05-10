#include "CircularBuffer.h"
#include "Utils.h"
#include <stdlib.h>
#include <string.h>

typedef struct CircularBufferStruct
{
    int count;
    int capacity;
    int * values;
} CircularBufferStruct;

CircularBuffer CircularBuffer_Create(int capacity)
{
    CircularBuffer tmp;
    tmp = malloc(sizeof(CircularBufferStruct));
    tmp->count = 0;
    tmp->capacity = capacity;
    tmp->values = malloc(capacity * sizeof(int));  
    return tmp;
}

void CircularBuffer_Destroy(CircularBuffer buffer)
{
    free(buffer->values);
    free(buffer);
}

void CircularBuffer_Print(CircularBuffer buffer)
{
    if(buffer->count == 0)
    {
        FormatOutput("Circular buffer content:\n<>\n\0");
    }
    else
    {
        FormatOutput("Circular buffer content:\n<%d>\n\0", buffer->values[0]);
    }
}

void CircularBuffer_Put(CircularBuffer buffer,int value)
{
    buffer->values[buffer->count] = value;
    buffer->count+=1;
}

