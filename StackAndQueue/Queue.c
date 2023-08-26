/**
*****************************************************************************
* @file             :Queue.c
* @author           :Ahmed Elzaki
* @brief            :Simple Implementation of Queue Data Structure
*****************************************************************************
*/

/*********************** Includes Section Start ***********************/
#include "Data_Structure.h"
/*********************** Includes Section End ***********************/

Queue *createQueue()
{
    Queue *q;
    q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    q->front = 0;
    q->last = 0;
    q->size = 0;
    q->capacity = INITIAL_CAPACITY;
    q->data = malloc(sizeof(int) * q->capacity);
    if (q->data == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return q;
}

Status enQueue(Queue *q, int data)
{
    if (q == NULL)
    {
        return NULLEror;
    }
    if (q->size == q->capacity)
    {
        q->capacity *= 2;
        q->data = realloc(q->data, sizeof(int) * q->capacity);
        if (q->data == NULL)
        {
            puts("Memory rallocation failed");
            exit(EXIT_FAILURE);
        }
    }

    if (q->last == q->capacity)
    {
        q->last = 0;
    }

    q->data[q->last] = data;
    q->last++;
    q->size++;

    return Done;
}

Status deQueue(Queue *q, int *data)
{
    if (q == NULL || data == NULL)
    {
        puts("Queue is Empty");
        return NULLEror;
    }
    if (q->size == 0)
    {
        puts("Queue is Empty");
        return Empty;
    }

    if (q->front == q->capacity)
    {
        q->front = 0;
    }

    *data = q->data[q->front];
    q->size--;
    q->front++;

    if (q->size == 0)
    {
        q->last = 0;
        q->front = 0;
    }

    return Done;
}

Status QueueFront(Queue *q, int *data)
{
    if (q == NULL || q->size == 0)
    {
        puts("Queue is empty");
        return NotOk;
    }
    *data = (q->data[q->front]);
    return Done;
}

Status QueueLast(Queue *q, int *data)
{
    if (q == NULL || q->size == 0)
    {
        puts("Queue is empty");
        return NotOk;
    }
    *data = q->data[(q->last == 0 ? (q->size) : (q->last)) - 1];
    return Done;
}

uint8_t isQueueEmpty(Queue *q)
{
    return q->size == 0;
}

void freeQueue(Queue *q)
{
    free(q->data);
    free(q);
    q = NULL;
}
