/**
*****************************************************************************
* @file             :Queue.c
* @author           :Ahmed Elzaki
* @brief            :Simple Implementation of Stack Data Structure
*****************************************************************************
*/

/*********************** Includes Section Start ***********************/
#include "Data_Structure.h"
/*********************** Includes Section End ***********************/

Stack *createStack()
{
    Stack *s;
    s = malloc(sizeof(Stack));

    if (s == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    s->data = malloc(sizeof(int) * s->capacity);
    if (s->data == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return s;
}

Status push(Stack *s, int data)
{
    if (s->data == NULL)
    {
        puts("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    if (s->top == s->capacity - 1)
    {
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(int) * s->capacity);
        if (s->data == NULL)
        {
            puts("Memory reallocation failed");
            exit(EXIT_FAILURE);
        }
    }

    s->top++;
    s->data[s->top] = data;

    return Done;
}

Status pop(Stack *s, int *data)
{
    if (s->top == -1)
    {
        puts("Stack is empty");
        return Empty;
    }

    *data = s->data[s->top];
    s->top--;

    if (s->top < s->capacity / 4)
    {
        s->capacity /= 2;
        s->data = realloc(s->data, sizeof(int) * s->capacity);
        if (s->data == NULL)
        {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return Done;
}
Status top(Stack *s, int *data)
{
    if (s->top == -1)
    {
        puts("Stack is empty");
        return Empty;
    }

    *data = s->data[s->top];

    return Done;
}

uint8_t isStackEmpty(Stack *s)
{
    return s->top == -1;
}

size_t getStackSize(Stack *s)
{
    return s->top + 1;
}

void freeStack(Stack *s)
{
    free(s->data);
    free(s);
    s = NULL;
}
