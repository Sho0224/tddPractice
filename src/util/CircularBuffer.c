#include "CircularBuffer.h"
#include "Utils.h"
#include <stdlib.h>
#include <string.h>

typedef struct CircularBufferStruct
{
    int count;
    int index;
    int outdex;
    int capacity;
    int * values;
} CircularBufferStruct;

int tmpValue = 0;
struct CircularBufferStruct tmp = { 0, 0, 0, 0, &tmpValue };
 
CircularBuffer CircularBuffer_Create(int capacity)
{
   return (CircularBuffer)&tmp;
}

void CircularBuffer_Destroy(CircularBuffer buffer)
{

}

void CircularBuffer_Print(CircularBuffer buffer)
{
    FormatOutput("Circular buffer content:\n<>\n");
}
