#include <stdio.h>
#include <string.h>
#include "mymemory.h"

int main(){
    printf("shell> start\n");
    printf("\n============================\n\n START OF DEMONSTRATION \n\n============================\n ");
    initialize();


    printf("Will allocate memory for 5 pointers.\n Press any character to continue");
    getchar();

   char * ptr1 = (char *) mymalloc(15);
   strcpy(ptr1, "memory_data_1");

   char * ptr2 = (char *) mymalloc(25);
   strcpy(ptr2, "memory_data_2");

   char * ptr3 = (char *) mymalloc(25);
   strcpy(ptr3, "memory_data_3");

   char * ptr4 = (char *) mymalloc(25);
   strcpy(ptr4, "memory_data_4");

   char * ptr5 = (char *) mymalloc(25);
   strcpy(ptr5, "memory_data_5");

    printf("\n\nAllocated memory for 5 pointers.\n\n");

    printf("\nPress any character to continue\n");
    getchar();

    printmemory();
    printsegmenttable();

    printf("\nptr2, ptr3, ptr4, ptr5, will be freed. \nPress any character to continue");
    getchar();

    myfree(ptr2);
    myfree(ptr3);
    myfree(ptr4);
    myfree(ptr5);

    printf("\n\nFreed all pointers except the first one.\nPress any key to continue\n\n");
    getchar();
    printmemory();
    printsegmenttable();

    printf("\n\nWill start defragmenting  the memory.\n Press any key to continue.\n");
    getchar();
    mydefrag(segmenttable);


    printf("\n\nDefragmented the memory. Will display the memory and the segmenttable.\nPress any key to continue.\n\n");
    getchar();
    printmemory();
    printsegmenttable();

    ///check if memory is reused after defrag
    printf("\n\n Allocated a pointer in order to demonstrate that the free, defragmented memory is reused. \nPress any key to continue\n\n");
    getchar();
    char * ptr6 = (char *) mymalloc(101);
    strcpy(ptr6, "__REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED___");

    printmemory();
    printsegmenttable();

    printf("\n\nFree the last allocated pointer, allocate memory for a new pointer, and defragmentate.\n Press any key to conitnue.\n\n");
    getchar();
    ptr2 = (char *)mymalloc(15);
    strcpy(ptr2,"This is new data");
    myfree(ptr6);
    mydefrag(segmenttable);
    printf("\n\nOperations done. Display the memory and segmenttable\nPress any key to continue.\n");
    getchar();
    printmemory();
    printsegmenttable();

    printf("\n============================\n\n END OF DEMONSTRATION \n\n============================\n ");

    printf("shell> end\n");
return 0;
}
