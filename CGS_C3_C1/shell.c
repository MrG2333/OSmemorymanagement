#include <stdio.h>
#include <string.h>
#include "mymemory.h"

void main(){
    printf("shell> start\n");

    initialize();

   char * ptr1 = (char *) mymalloc(10);

   strcpy(ptr1, "this test");
   printf("shell> content of allocated memory: %s\n", ptr1);

   char * ptr2 = (char *) mymalloc(300);
   strcpy(ptr2, "this test");       ///both segments will be pointing to the same string literal, because of this both segment startingpoints will be the same
   printf("shell> content of allocated memory: %s\n", ptr2);


    printmemory();

    printsegmenttable();

    printf("shell> end\n");
}
