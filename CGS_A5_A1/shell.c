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

   char * ptr2 = (char *) mymalloc(15);
   strcpy(ptr2, "memory_data_2");

   char * ptr3 = (char *) mymalloc(15);
   strcpy(ptr3, "memory_data_3");

   char * ptr4 = (char *) mymalloc(15);
   strcpy(ptr4, "memory_data_4");

   char * ptr5 = (char *) mymalloc(15);
   strcpy(ptr5, "memory_data_5");

    printf("\n\nAllocated memory for 5 pointers.\n\n");

    printf("\nPress any character to continue\n");
    getchar();

    printmemory();
    printsegmenttable();

    printf("\n\nFree ptr2 of size 25, display segmenttable and reallocate the memory to a pointer of the same size to demonstrate the propper functioning of mymalloc.\n Press any key to continue.\n\n");
    getchar();
    myfree(ptr2);

    printsegmenttable();
    printf("\n\n run mymalloc for the same size as the freed pointer.\n Press any key to continue.\n\n");
    getchar();

    char * ptr10 = NULL;
    ptr10 = (char *)mymalloc(15);
    strcpy(ptr10,"12345678901234");

    printsegmenttable();
    printf("\n\n Observe how mymalloc can reuse memory segments of the same size.\n Press any key to continue.\n\n");
    getchar();



    printf("\n All pointers with the exception of 2 not adjiacent ones will be freed in order to demonstrate the defragmentation and free space segment compresion. \nPress any character to continue");
    getchar();
    myfree(ptr10);
    myfree(ptr3);

    myfree(ptr5);

    printf("\n\nFreed all pointers except 2 not adjiacent ones(1st and 4th).\nPress any key to continue\n\n");
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
    printf("\n\n Observe how the data has been moved in the memory.\nPress any key to continue.\n\n");
    getchar();

    ///check if memory is reused after defrag
    printf("\n\n Allocated a pointer in order to demonstrate that the free, defragmented memory is reused. \nPress any key to continue\n\n");
    getchar();
    char * ptr6 = (char *) mymalloc(101);
    strcpy(ptr6, "__REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED_____REUSED___REUSED___");

    printf("\n\n Allocation done check memory and segmenttable. \nPress any key to continue\n\n");
    getchar();

    printmemory();
    printsegmenttable();

    printf("\n============================\n\n END OF DEMONSTRATION \n\n============================\n ");

    printf("shell> end\n");
return 0;
}
