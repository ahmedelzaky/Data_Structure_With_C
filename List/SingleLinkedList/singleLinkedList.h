#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H
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

typedef struct slList
{
    int32_t data;
    struct slList *next;
} Node;

Statue appendNode(struct slList **head, int32_t data);
Statue pushNode(struct slList **head, int32_t data);
Statue getNodeData(struct slList *list, size_t index, int32_t *data);
Statue setNodeData(struct slList *list, size_t index, int32_t data);
Statue deleteNode(struct slList **list, size_t index);
Statue insertNode(struct slList **list, size_t index, int32_t data);
size_t getListSize(struct slList *list);
Statue displayList(struct slList *list);
Statue sortList(struct slList *list);
Statue swapNodes(struct slList *list, size_t index1, size_t index2);
Statue reverseList(struct slList **list);
size_t searchInList(struct slList *list, int32_t data);
void freeList(struct slList *list);

#endif