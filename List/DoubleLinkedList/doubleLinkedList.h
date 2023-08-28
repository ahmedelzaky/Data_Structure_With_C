#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum
{
    Done,
    NULL_ERROR,
    OUT_OFF_BOUNDRY,
    NOT_FOUND = -1,
} Statue;

typedef struct dlList
{
    int32_t data;
    struct dlList *next;
    struct dlList *prev;
} Node;

Statue appendNode(struct dlList **head, int32_t data);
Statue pushNode(struct dlList **head, int32_t data);
Statue getNodeData(struct dlList *list, size_t index, int32_t *data);
Statue setNodeData(struct dlList *list, size_t index, int32_t data);
Statue deleteNode(struct dlList **list, size_t index);
Statue insertNode(struct dlList **list, size_t index, int32_t data);
size_t getListSize(struct dlList *list);
Statue displayList(struct dlList *list);
Statue sortList(struct dlList *list);
size_t searchInList(struct dlList *list, int32_t data);
void freeList(struct dlList *list);

#endif