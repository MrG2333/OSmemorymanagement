/* mymemory.c
 *
 * provides interface to memory management
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mymemory.h"


// our memory
Byte        mymemory [MAXMEM] ;
Segment_t * segmenttable = NULL;


void initialize ()
{
   printf ( "initialize> start\n");
   // set memory to 0
	for(int i=0;i < MAXMEM;i++) mymemory[i]='\0';


    // create segment table
    // contains one segment description that declares the whole memory
    // as one free segment
    segmenttable = (Segment_t *)(mymemory);
    segmenttable->allocated = FALSE;
    segmenttable->size = MAXMEM;
    segmenttable->start = mymemory;
    segmenttable->next =  NULL;

   //
   // create a single segment descriptor

   // initialise the segment

   printf ( "initialize> end\n");
}


void * mymalloc ( size_t size )
{
    printf ( "mymalloc> start\n");
    Segment_t * ptrToFree = NULL;
    Segment_t * newSegmentAfterSplit = NULL;

    ptrToFree = findFree( segmenttable,size);

    if(ptrToFree != NULL)
    {
        ///calculate sizes after split
        size_t sizeOfFreeSegment = ptrToFree->size;
        size_t sizeOfSegmentAfterSplit = sizeOfFreeSegment - size;

        newSegmentAfterSplit = (Segment_t * )(ptrToFree->start + sizeof(Segment_t) + sizeof(Byte)*size); ///maybe add +1

        newSegmentAfterSplit->allocated=FALSE;
        newSegmentAfterSplit->next=NULL;
        newSegmentAfterSplit->size=sizeOfSegmentAfterSplit;
        newSegmentAfterSplit->start = ptrToFree->start + sizeof(Segment_t)+sizeof(Byte)*size;             ///Is this right???
                                                                                        ///why does printsegmentable print the wrong thing???

        ptrToFree->allocated=TRUE;
        ptrToFree->size = size;
        insertAfter(ptrToFree,newSegmentAfterSplit);
        return ptrToFree;
    }
    printf( "mymalloc> end\n");
    return NULL;


}

void myfree ( void * ptr )
{
   printf ( "myfree> start\n");

}

void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");

}


// helper functions for management segmentation table
Segment_t * findFree ( Segment_t * list, size_t size )
{
    printf ( "findFree> start\n");
    while(list!=NULL)
    {
        if(list->allocated == FALSE && list->size > size)                 ///check if size can be <= or always <
            return list;
        list=list->next;
    }
    printf( "findFree> end\n" );
    return NULL;
}

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
    printf("insertAfter> start\n");
        oldSegment->next = newSegment;
    printf("insertAfter> end\n");
}

Segment_t * findSegment ( Segment_t * list, void * ptr )
{


}

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}

void printmemory ()
{
    ///we print the memory by printing each byte in a way
    /// construct the strings print in batches of 10

    ///could have made the strings so that only one pass takes place
    ///but it does not matter at this time
    ///TODO: re-write with sprintf
    char aux;

    for(int i=0;i< MAXMEM;i=i+10)
    {
        printf("\n[%4d]", i);
        for(int j = 0; j < 10 && i+j < MAXMEM;j++)
        {
            printf(" %02x",mymemory[i+j]);
        }
        if(i==1020)
            printf("                   | ");
        else
            printf(" | ");
       // for(int j = )
        for(int j = 0;j<10 && i+j < MAXMEM; j++)
        {
                aux = isPrintable(mymemory[i+j]);
                if(aux != 0)
                    printf("%c",aux);
                else
                    printf(".");
        }

    }

}



void printsegmenttable()
{

    ///segmenttable is global
    Segment_t * auxSegmentReader;
    auxSegmentReader = segmenttable;
    unsigned int counter = 0;

    while(auxSegmentReader != NULL)
    {
        printf("\nSegment %d:\n",counter);
        counter++;
        if(auxSegmentReader->allocated == FALSE)
            printf("\tallocated = FALSE\n");
        else
            printf("\tallocated = TRUE\n");

        printf("\tstart = %p\n", auxSegmentReader->start);
        printf("\tsize = %ld\n",auxSegmentReader->size);

        auxSegmentReader = auxSegmentReader->next;
    }
}

void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
}
