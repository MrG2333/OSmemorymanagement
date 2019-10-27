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
	for(int i=0;i < MAXMEM;i++) mymemory[i]='\0';

    segmenttable = (Segment_t *) malloc(sizeof(Segment_t)) ;
    segmenttable->allocated = FALSE;
    segmenttable->size = MAXMEM;
    segmenttable->start = mymemory;
    segmenttable->next =  NULL;

   printf ( "initialize> end\n");
}


void * mymalloc ( size_t size )
{
    printf ( "mymalloc> start\n");

    printf( "mymalloc> end\n");
    return NULL;


}


void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");
 
   printf( "mydefrag> end\n");
}


// helper functions for management segmentation table
Segment_t * findFree ( Segment_t * list, size_t size )
{
    printf ( "findFree> start\n");
 
    printf( "findFree> end\n" );
    return NULL;
}

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
    printf("insertAfter> start\n");
    printf("insertAfter> end\n");
}

Segment_t * findSegment ( Segment_t * list, void * ptr )
{

}

void myfree ( void * ptr )
{
   printf ( "myfree> start\n");


   printf("myfree> end\n");
}

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}

void printmemory ()
{

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
