/**
*****************************************************************************
* @file             :singleLinkedList.c
* @author           :Ahmed Elzaki
* @brief            :Simple Implementation of Single Linked List
*****************************************************************************
*/

/*********************** Includes Section Start ***********************/
#include "singleLinkedList.h"
/*********************** Includes Section End ***********************/

Statue appendNode(struct slList **head, int32_t data)
{

    struct slList *newNode = malloc(sizeof(struct slList));
    struct slList *tempList = *head;

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
            tempList = (struct slList *)tempList->next;
        }
        tempList->next = newNode;
    }

    return Done;
}

Statue pushNode(struct slList **head, int32_t data)
{

    struct slList *newNode = malloc(sizeof(struct slList));

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

Statue getNodeData(struct slList *list, size_t index, int32_t *data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct slList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = (struct slList *)tempList->next;
    }
    *data = tempList->data;

    return Done;
}

Statue setNodeData(struct slList *list, size_t index, int32_t data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct slList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = (struct slList *)tempList->next;
    }
    tempList->data = data;

    return Done;
}

Statue deleteNode(struct slList **list, size_t index)
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

    struct slList *temp1 = *list;
    struct slList *temp2;

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

Statue insertNode(struct slList **list, size_t index, int32_t data)
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

    struct slList *temp1 = *list;
    struct slList *newNode = malloc(sizeof(struct slList));

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;

    if (index == 0)
    {
        pushNode(list, data);
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

size_t getListSize(struct slList *list)
{
    if (list == NULL)
    {
        puts("Error!!");
        return 0;
    }
    struct slList *tempList = list;
    size_t size = 0;

    while (tempList != NULL)
    {
        tempList = (struct slList *)tempList->next;
        size++;
    }

    return size;
}

Statue displayList(struct slList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct slList *tempList = list;
    printf("[");

    while (tempList != NULL)
    {
        printf(" %d ,", tempList->data);
        tempList = (struct slList *)tempList->next;
    }
    printf("\b]");

    return Done;
}

size_t searchInList(struct slList *list, int32_t data)
{

    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct slList *tempList = list;
    size_t index = 0;

    while (tempList->data != data)
    {
        index++;
        tempList = (struct slList *)tempList->next;
        if (tempList == NULL)
        {
            index = NOT_FOUND;
            break;
        }
    }

    return index;
}

Statue sortList(struct slList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct slList *tempList = list;
    struct slList *temp = list->next;
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

void freeList(struct slList *list)
{
    struct slList *tempList;
    while (list != NULL)
    {
        tempList = list;
        list = list->next;
        free(tempList);
    }
}
