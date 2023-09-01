#include "singleLinkedList.h"
#include <time.h>

int main()
{
    struct slList *list1 = NULL;
    struct slList *list2 = NULL;
    struct slList *list3 = NULL;
    struct slList *list4 = NULL;

    puts("<============== Start Append Test ==============>");

    for (int i = 1; i <= 20; i++)
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

    printf("index of 8 in list1 : %ld\n", searchInList(list1, 8));

    printf("List1: ");
    displayList(list1);

    freeList(list1);
    puts("\n<============== End Append Test ==============>");

    puts("\n<============== Start Push Test ==============>");

    for (int i = 1; i <= 20; i++)
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
    printf("index of 8 in list2 : %ld\n", searchInList(list2, 8));

    printf("List2: ");
    displayList(list2);

    freeList(list2);
    puts("\n<============== End Push Test ==============>");

    puts("\n<============== Start Sort Test ==============>");

    srand(time(NULL));

    for (int i = 1; i <= 20; i++)
    {
        int randomNumber = rand() % 20 + 1;
        appendNode(&list3, randomNumber);
    }

    printf("Before Sorting List3: ");
    displayList(list3);

    sortList(list3);

    printf("\n\nAfter Sorting List3: ");
    displayList(list3);

    freeList(list3);
    puts("\n<============== End Sort Test ==============>");

    puts("\n<============== Start Swap & Reverse Test ==============>");
    for (int i = 1; i <= 20; i++)
    {
        appendNode(&list4, i);
    }

    printf("Before Reversing List4: ");
    displayList(list4);

    reverseList(&list4);
    printf("\n\nAfter Reversing List4: ");
    displayList(list4);

    swapNodes(list4, 5, 10);

    printf("\n\nAfter Swapping List4: ");
    displayList(list4);

    freeList(list4);
    puts("\n<============== End Swap & Reverse Test ==============>");

    return 0;
}
