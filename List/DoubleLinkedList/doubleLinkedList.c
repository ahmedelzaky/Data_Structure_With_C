/**
*****************************************************************************
* @file             :doubleLinkedList.c
* @author           :Ahmed Elzaki
* @brief            :Simple Implementation of Single Linked List
*****************************************************************************
*/

/*********************** Includes Section Start ***********************/
#include "doubleLinkedList.h"
/*********************** Includes Section End ***********************/

Statue appendNode(struct dlList **head, int32_t data)
{
    struct dlList *newNode = malloc(sizeof(struct dlList));
    struct dlList *tempList = *head;

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        while (tempList->next != NULL)
        {
            tempList = tempList->next;
        }
        tempList->next = newNode;
        newNode->prev = tempList;
    }

    return Done;
}

Statue pushNode(struct dlList **head, int32_t data) {}

Statue getNodeData(struct dlList *list, size_t index, int32_t *data) {}

Statue setNodeData(struct dlList *list, size_t index, int32_t data) {}

Statue deleteNode(struct dlList **list, size_t index) {}

Statue insertNode(struct dlList **list, size_t index, int32_t data) {}

size_t getListSize(struct dlList *list)
{
    if (list == NULL)
    {
        puts("Error!!");
        return 0;
    }
    struct dlList *tempList = list;
    size_t size = 0;

    while (tempList != NULL)
    {
        tempList = tempList->next;
        size++;
    }

    return size;
}

Statue displayList(struct dlList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct dlList *tempList = list;
    printf("[");

    while (tempList != NULL)
    {
        printf(" %d ,", tempList->data);
        tempList = tempList->next;
    }
    printf("\b]\n");

    return Done;
}

Statue displayListReverse(struct dlList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct dlList *tempList = list;

    while (tempList->next != NULL)
    {
        tempList = tempList->next;
    }
    printf("[");

    while (tempList != NULL)
    {
        printf(" %d ,", tempList->data);
        tempList = tempList->prev;
    }

    printf("\b]\n");

    return Done;
}

Statue sortList(struct dlList *list) {}

size_t searchInList(struct dlList *list, int32_t data) {}

void freeList(struct dlList *list)
{

    struct dlList *tempList;
    while (list != NULL)
    {
        tempList = list;
        list = list->next;
        free(tempList);
    }
}