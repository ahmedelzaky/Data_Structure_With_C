#ifndef _DATA_STRUCTER_H
#define _DATA_STRUCTER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define INITIAL_CAPACITY 10

typedef enum
{
    Done,
    NotOk,
    NULLEror,
    Empty,

} Status;

// Stack
typedef struct
{
    int *data;
    size_t top;
    size_t capacity;
} Stack;

Stack *createStack();
Status push(Stack *s, int data);
Status pop(Stack *s, int *data);
Status top(Stack *s, int *data);
uint8_t isStackEmpty(Stack *s);
size_t getStackSize(Stack *s);
void freeStack(Stack *s);

// Queue
typedef struct
{
    int *data;
    size_t front;
    size_t last;
    size_t size;
    size_t capacity;
} Queue;

Queue *createQueue();
Status enQueue(Queue *q, int data);
Status deQueue(Queue *q, int *data);
Status QueueFront(Queue *q, int *data);
Status QueueLast(Queue *q, int *data);
uint8_t isQueueEmpty(Queue *q);
void freeQueue(Queue *q);

#endif
