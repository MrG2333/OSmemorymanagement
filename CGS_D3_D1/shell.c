#include <stdio.h>
#include <string.h>
#include "mymemory.h"

void main(){
    printf("shell> start\n");

    initialize();

    printmemory();

	printsegmenttable();

    printf("shell> end\n");
}
