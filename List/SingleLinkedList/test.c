#include "singleList.h"

int32_t data;
int32_t x = 3;
struct SingleList *list1 = NULL;
struct SingleList *list2 = NULL;

int main()
{
    puts("<=======Start Append Test=======>");
    for (size_t i = 1; i <= 10; i++)
    {
        appendNode(&list1, i);
    }

    insertNode(&list1, 5, 1);

    printf("size of list : %d \n", getListSize(list1));

    getNodeData(list1, x, &data);
    printf("data of index [%d] =  %d \n", x, data);

    deletNode(&list1, 0);

    setNodeData(list1, 4, 300);

    setNodeData(list1, 3, -1);

    displayList(list1);

    freeList(list1);
    puts("\n<=======End Append Test=======>");

    puts("\n<=======Start push Test=======>");

    for (size_t i = 1; i <= 10; i++)
    {
        pushNode(&list2, i);
    }
    
    insertNode(&list2, 5, 1);

    printf("size of list : %d \n", getListSize(list2));

    getNodeData(list2, x, &data);

    printf("data of index [%d] =  %d \n", x, data);

    deletNode(&list2, 0);

    setNodeData(list2, 4, 300);

    setNodeData(list2, 3, -1);

    displayList(list2);

    freeList(list2);

    puts("\n<=======End push Test=======>");
}