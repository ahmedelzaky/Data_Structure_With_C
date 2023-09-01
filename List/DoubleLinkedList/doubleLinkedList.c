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

Statue pushNode(struct dlList **head, int32_t data)
{
    struct dlList *newNode = malloc(sizeof(struct dlList));
    struct dlList *tempList = *head;

    if (newNode == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->next = tempList;
        tempList->prev = newNode;
        *head = newNode;
    }

    return Done;
}

Statue getNodeData(struct dlList *list, size_t index, int32_t *data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct dlList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = tempList->next;
    }
    *data = tempList->data;

    return Done;
}

Statue setNodeData(struct dlList *list, size_t index, int32_t data)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    size_t size = getListSize(list);
    struct dlList *tempList = list;
    if (index >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    for (size_t i = 0; i < index; i++)
    {
        tempList = tempList->next;
    }
    tempList->data = data;

    return Done;
}

Statue deleteNode(struct dlList **list, size_t index)
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

    struct dlList *tempList = *list;
    struct dlList *tempnode;

    if (index == 0)
    {
        *list = tempList->next;
        (*list)->prev = NULL;
    }
    else
    {
        for (size_t i = 0; i < index; i++)
        {
            tempList = tempList->next;
        }
        if (tempList->next == NULL)
        {
            tempList->prev->next = NULL;
        }
        else
        {
            tempnode = tempList->prev;
            tempnode->next = tempList->next;
            tempList->next->prev = tempnode;
        }
    }
    free(tempList);
    return Done;
}

Statue insertNode(struct dlList **list, size_t index, int32_t data)
{

    if (*list == NULL)
    {
        return NULL_ERROR;
    }

    size_t size = getListSize(*list);

    if (index > size)
    {
        return OUT_OFF_BOUNDRY;
    }

    struct dlList *tempList = *list;
    struct dlList *newNode = malloc(sizeof(struct dlList));

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
    else if (index == size)
    {
        appendNode(list, data);
    }

    else
    {
        for (size_t i = 0; i < index - 1; i++)
        {
            tempList = tempList->next;
        }
        newNode->next = tempList->next;
        newNode->prev = tempList;
        tempList->next->prev = newNode;
        tempList->next = newNode;
    }
    return Done;
}

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

Statue swapNodes(struct dlList *list, size_t index1, size_t index2)
{

    if (list == NULL)
    {
        return NULL_ERROR;
    }

    size_t size = getListSize(list);

    if (index1 >= size || index2 >= size)
    {
        return OUT_OFF_BOUNDRY;
    }

    struct dlList *tempList = list;
    struct dlList *tempNode1;
    struct dlList *tempNode2;
    size_t count = 0;
    int32_t tempData;

    if (index1 == index2)
    {
        return Done;
    }

    if (index1 > index2)
    {
        size_t temp = index1;
        index1 = index2;
        index2 = temp;
    }
    while (index2--)
    {
        if (index1 == count)
        {
            tempNode1 = tempList;
        }
        tempList = tempList->next;
        count++;
    }
    tempNode2 = tempList;

    tempData = tempNode1->data;
    tempNode1->data = tempNode2->data;
    tempNode2->data = tempData;

    return Done;
}

Statue reverseList(struct dlList **list)
{
    if (*list == NULL)
    {
        return NULL_ERROR;
    }

    struct dlList *tempList = *list;
    struct dlList *tempNode = NULL;

    while (tempList != NULL)
    {
        tempNode = tempList->prev;
        tempList->prev = tempList->next;
        tempList->next = tempNode;
        tempList = tempList->prev;
    }

    if (tempNode != NULL)
    {
        *list = tempNode->prev;
    }

    return Done;
}

Statue sortList(struct dlList *list)
{
    if (list == NULL)
    {
        return NULL_ERROR;
    }
    struct dlList *tempList = list;
    struct dlList *temp = list->next;
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

size_t searchInList(struct dlList *list, int32_t data)
{
    size_t index = 0;

    if (list == NULL)
    {
        puts("Error !!");
        return NULL_ERROR;
    }

    struct dlList *tempList = list;

    while (tempList->data != data)
    {
        index++;
        tempList = tempList->next;
        if (tempList == NULL)
        {
            index = NOT_FOUND;
            break;
        }
    }

    return index;
}

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
