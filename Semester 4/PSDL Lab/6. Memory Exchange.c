#include <stdio.h>
#include <stdlib.h>

void main(void) {
   int temp , i ;
   int source[] = {0x21,0x22,0x23,0x24,0x25} ; // Source memory block
   int dest[] = {0x99,0x98,0x97,0x96,0x95} ; // Destination memory block
   for(i = 0 ; i < 5 ; i++)
   {
       temp = source[i] ;
       source[i] = dest[i] ;
       dest[i] = temp ;
   }
   // OUTPUT USING PORT IF NEEDED
}
