/**
*****************************************************************************
* @file             :singleList.c
* @author           :Ahmed Elzaki
* @brief            :Simple Implementation of Single Linked List
*****************************************************************************
*/

/*********************** Includes Section Start ***********************/
#include "singleList.h"
/*********************** Includes Section End ***********************/

Statue appendNode(struct SingleList **head, int32_t data)
{

    struct SingleList *n = malloc(sizeof(struct SingleList));
    struct SingleList *temp = *head;

    if (n == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    n->data = data;
    n->next = NULL;

    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = (struct SingleList *)temp->next;
        }
        temp->next = n;
    }

    return Done;
}

Statue pushNode(struct SingleList **head, int32_t data)
{

    struct SingleList *n = malloc(sizeof(struct SingleList));

    if (n == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    n->data = data;
    n->next = NULL;

    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        n->next = *head;
        *head = n;
    }

    return Done;
}

Statue getNodeData(struct SingleList *list, size_t index, int32_t *data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct SingleList *temp = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        temp = (struct SingleList *)temp->next;
    }
    *data = temp->data;

    return Done;
}

Statue setNodeData(struct SingleList *list, size_t index, int32_t data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct SingleList *temp = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        temp = (struct SingleList *)temp->next;
    }
    temp->data = data;

    return Done;
}

Statue deleteNode(struct SingleList **list, size_t index)
{
    if (*list == NULL)
    {
        return NULL_ERROR;
    }

    size_t size = getListSize(*list);

    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    struct SingleList *temp1 = *list;
    struct SingleList *temp2;

    if (index == 0)
    {
        *list = temp1->next; // Update the list pointer
        free(temp1);
    }
    else
    {
        for (size_t i = 0; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
    return Done;
}

Statue insertNode(struct SingleList **list, size_t index, int32_t data)
{
    if (*list == NULL)
    {
        return NULL_ERROR;
    }

    size_t size = getListSize(*list);

    if (index >= size + 1)
    {
        return OUT_OFF_BOUNDRY;
    }

    struct SingleList *temp1 = *list;
    struct SingleList *n = malloc(sizeof(struct SingleList));

    if (n == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    n->data = data;

    if (index == 0)
    {
        n->next = temp1;
        *list = n;
    }

    else
    {
        for (size_t i = 0; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        n->next = temp1->next;
        temp1->next = n;
    }
    return Done;
}

size_t getListSize(struct SingleList *list)
{
    if (list == NULL)
    {
        puts("Error!!");
        return 0;
    }
    struct SingleList *temp = list;
    size_t size = 0;

    while (temp != NULL)
    {
        temp = (struct SingleList *)temp->next;
        size++;
    }

    return size;
}

Statue displayList(struct SingleList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct SingleList *temp = list;
    printf("[");

    while (temp != NULL)
    {
        printf(" %d ,", temp->data);
        temp = (struct SingleList *)temp->next;
    }
    printf("\b]");

    return Done;
}

size_t searchInList(struct SingleList *list, int32_t data)
{

    if (list == NULL)
    {
        return NOT_FOUND;
    }
    struct SingleList *temp = list;
    size_t index = -1;

    while (temp->data != data)
    {
        index++;
        temp = (struct SingleList *)temp->next;
        if (temp == NULL)
        {
            index = NOT_FOUND;
            break;
        }
    }

    return index;
}

void freeList(struct SingleList *list)
{
    struct SingleList *temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}
