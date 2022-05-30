#include <stdio.h>
#include <stdlib.h>
#include<pic18f4550.h>

void main(void) {
   int num1 = 0x06 , num2 = 0x02 ;
   int d ;
   d = 0 ;
   d = num1/num2 ;
   TRISD = 0 ;
   PORTD = d ;
   int n1 , n2 ;
   n1 = 0x23 , n2 = 0x10 ;
   int prod = 0 ;
   for (int i = 1 ; i <= n2 ; i++){
      prod = prod + n1 ;
   } // OR prod = n1*n2 
   TRISB = 0 ;
   PORTB = prod ;
}
