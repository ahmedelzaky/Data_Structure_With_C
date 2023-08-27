#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H
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

typedef struct SingleList
{
    int32_t data;
    struct SingleList *next;
} Node;

Statue appendNode(struct SingleList **head, int32_t data);
Statue pushNode(struct SingleList **head, int32_t data);
Statue getNodeData(struct SingleList *list, size_t index, int32_t *data);
Statue setNodeData(struct SingleList *list, size_t index, int32_t data);
Statue deleteNode(struct SingleList **list, size_t index);
Statue insertNode(struct SingleList **list, size_t index, int32_t data);
size_t getListSize(struct SingleList *list);
Statue displayList(struct SingleList *list);
Statue sortList(struct SingleList *list);
size_t searchInList(struct SingleList *list, int32_t data);
void freeList(struct SingleList *list);

#endif