#ifndef D_CircularBuffer_H
#define D_CircularBuffer_H

typedef struct CircularBufferStruct * CircularBuffer;
CircularBuffer CircularBuffer_Create(int capacity);
void CircularBuffer_Destroy(CircularBuffer buffer);
void CircularBuffer_Print(CircularBuffer buffer);
void CircularBuffer_Put(CircularBuffer buffer,int value); 
#endif  /* D_CircularBuffer_H */
