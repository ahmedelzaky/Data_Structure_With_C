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

    struct SingleList *newNode = malloc(sizeof(struct SingleList));
    struct SingleList *tempList = *head;

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (tempList->next != NULL)
        {
            tempList = (struct SingleList *)tempList->next;
        }
        tempList->next = newNode;
    }

    return Done;
}

Statue pushNode(struct SingleList **head, int32_t data)
{

    struct SingleList *newNode = malloc(sizeof(struct SingleList));

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
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
    struct SingleList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = (struct SingleList *)tempList->next;
    }
    *data = tempList->data;

    return Done;
}

Statue setNodeData(struct SingleList *list, size_t index, int32_t data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct SingleList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = (struct SingleList *)tempList->next;
    }
    tempList->data = data;

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
    struct SingleList *newNode = malloc(sizeof(struct SingleList));

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;

    if (index == 0)
    {
        newNode->next = temp1;
        *list = newNode;
    }

    else
    {
        for (size_t i = 0; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        newNode->next = temp1->next;
        temp1->next = newNode;
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
    struct SingleList *tempList = list;
    size_t size = 0;

    while (tempList != NULL)
    {
        tempList = (struct SingleList *)tempList->next;
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
    struct SingleList *tempList = list;
    printf("[");

    while (tempList != NULL)
    {
        printf(" %d ,", tempList->data);
        tempList = (struct SingleList *)tempList->next;
    }
    printf("\b]");

    return Done;
}

size_t searchInList(struct SingleList *list, int32_t data)
{

    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct SingleList *tempList = list;
    size_t index = 0;

    while (tempList->data != data)
    {
        index++;
        tempList = (struct SingleList *)tempList->next;
        if (tempList == NULL)
        {
            index = NOT_FOUND;
            break;
        }
    }

    return index;
}

Statue sortList(struct SingleList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct SingleList *tempList = list;
    struct SingleList *temp = list->next;
    int32_t tempData = 0;
    size_t size = getListSize(list);

    for (size_t i = 0; i < size; i++)
    {
        int8_t flag = 1;
        while (temp != NULL)
        {
            if (tempList->data > temp->data)
            {
                flag = 0;
                tempData = tempList->data;
                tempList->data = temp->data;
                temp->data = tempData;
            }
            temp = temp->next;
            tempList = tempList->next;
        }
        if (flag)
        {
            return Done;
        }
        tempList = list;
        temp = list->next;
    }

    return Done;
}

void freeList(struct SingleList *list)
{
    struct SingleList *tempList;
    while (list != NULL)
    {
        tempList = list;
        list = list->next;
        free(tempList);
    }
}
