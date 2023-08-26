#include "singleList.h"

int main()
{
    struct SingleList *list1 = NULL;
    struct SingleList *list2 = NULL;

    // Append Test
    puts("<======= Start Append Test =======>");

    for (int i = 1; i <= 10; i++)
    {
        appendNode(&list1, i);
    }

    deleteNode(&list1, 0);
    insertNode(&list1, 5, 1);
    setNodeData(list1, 4, 300);
    setNodeData(list1, 3, -1);

    printf("Size of list1 : %lu\n", getListSize(list1));

    int32_t data;
    if (getNodeData(list1, 2, &data) == Done)
    {
        printf("Data at index [2] : %d\n", data);
    }
    else
    {
        printf("Failed to get data at index 3.\n");
    }

    printf("index of 8 in list1 : %d\n", searchInList(list1, 8));

    printf("List1: ");
    displayList(list1);

    freeList(list1);
    puts("\n<======= End Append Test =======>");

    // Push Test
    puts("\n<======= Start Push Test =======>");

    for (int i = 1; i <= 10; i++)
    {
        pushNode(&list2, i);
    }

    deleteNode(&list2, 0);
    insertNode(&list2, 5, 1);
    setNodeData(list2, 4, 300);
    setNodeData(list2, 3, -1);

    printf("Size of list2 : %lu\n", getListSize(list2));

    if (getNodeData(list2, 2, &data) == Done)
    {
        printf("Data at index [2] : %d\n", data);
    }
    else
    {
        printf("Failed to get data at index 3.\n");
    }
    printf("index of 8 in list2 : %d\n", searchInList(list2, 8));

    printf("List2: ");
    displayList(list2);

    freeList(list2);
    puts("\n<======= End Push Test =======>");

    return 0;
}
