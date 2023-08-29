#include <stdio.h>
#include <stdlib.h>
#include "Data_Structure.h"

int data;

Queue *myQueue;
Stack *myStack;

int main()
{
    puts("<==========Start Queue Test==========>");
    myQueue = createQueue();

    for (size_t i = 1; i <= 30; i++)
    {
        enQueue(myQueue, i);
    }

    printf("Size of Queue : %ld\n", myQueue->size);
    printf("capacity of Queue : %ld\n", myQueue->capacity);
    QueueFront(myQueue, &data);
    printf("First : %d\n", data);
    QueueLast(myQueue, &data);
    printf("Last : %d\n", data);

    //  getchar();
    printf("[");
    while (!isQueueEmpty(myQueue))
    {
        deQueue(myQueue, &data);
        printf(" %d,", data);
    }
    printf("\b]");

    freeQueue(myQueue);
    puts("\n<==========Finish Queue Test==========>");

    puts("\n<==========Start Stack Test==========>");

    myStack = createStack();

    for (size_t i = 1; i <= 30; i++)
    {
        push(myStack, i);
    }

    printf("Size of Stack : %ld\n", getStackSize(myStack));
    printf("capacity of Queue : %ld\n", myStack->capacity);
    top(myStack, &data);
    printf("Top : %d\n", data);

    //  getchar();
    printf("[");
    while (!isStackEmpty(myStack))
    {
        pop(myStack, &data);
        printf(" %d,", data);
    }
    printf("\b]");

    freeStack(myStack);

    puts("\n<==========Finish Stack Test==========>");

    return 0;
}