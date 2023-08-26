#include "singleList.h"

int32_t data;
int32_t x = 3;
struct SingleList *list = NULL;

int main()
{
    for (size_t i = 1; i <= 10; i++)
    {
        appendNode(&list, i);
    }

    insertNode(&list, 5, 1);

    printf("size of list : %d \n", getListSize(list));

    getNodeData(list, x, &data);
    printf("data of index [%d] =  %d \n", x, data);
    deletNode(&list, 0);
    setNodeData(list, 4, 300);
    setNodeData(list, 9, -1);
    displayList(list);

    freeList(list);
}