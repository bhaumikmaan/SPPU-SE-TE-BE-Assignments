#include <stdio.h>
#include <stdlib.h>
#include<pic18f4550.h>

void main(main){
   int temp , i ;
   int source[] = {0x21,0x22,0x23,0x24,0x25} ; // Source memory block
   int dest[] = {0x00,0x00,0x00,0x00,0x00} ; // Destination memory block
   for(i = 0 ; i <= 5 ; i++)
   {
      dest[i] = source[i] ;
   } 
  // OUTPUT USING PORT IF NEEDED
}
