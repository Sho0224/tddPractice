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
    FormatOutput("Circular buffer content:\n<");
    for(int i = 0; i < buffer->count; i++)
    {
        FormatOutput("%d", buffer->values[i]);
        if(i != buffer->count -1)
        {
            FormatOutput(", ");
        }
    }
    FormatOutput(">\n\0");
}

void CircularBuffer_Put(CircularBuffer buffer,int value)
{
    buffer->values[buffer->count] = value;
    buffer->count+=1;
}

