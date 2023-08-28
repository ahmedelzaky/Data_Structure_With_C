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

Statue appendNode(struct dlList **head, int32_t data) {}
Statue pushNode(struct dlList **head, int32_t data) {}
Statue getNodeData(struct dlList *list, size_t index, int32_t *data) {}
Statue setNodeData(struct dlList *list, size_t index, int32_t data) {}
Statue deleteNode(struct dlList **list, size_t index) {}
Statue insertNode(struct dlList **list, size_t index, int32_t data) {}
size_t getListSize(struct dlList *list) {}
Statue displayList(struct dlList *list) {}
Statue sortList(struct dlList *list) {}
size_t searchInList(struct dlList *list, int32_t data) {}
void freeList(struct dlList *list) {}