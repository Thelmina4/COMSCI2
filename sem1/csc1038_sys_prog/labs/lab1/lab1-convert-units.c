/* 
convert-units.c
Author: Thelma
input is cm
output is inches ( 2.54 centimetres in every inch)
print the result with 2 digits after decimal point
*/

#include<stdio.h>
#include<stdlib.h>

/* Can I put the define outside the script? 
   does this make it global?
*/
#define defcm2inch 2.54

int main(int argc, char*argv[]){
   /* 
    argc is a count of thhe command line args
    argv is a string, need to convert to int w atoi()
   */
   float cm2inch = 2.54;
   int centimeters = 0;
   centimeters = atoi(argv[1]);
//    printf("%d\n", centimeters);
   printf("%.2f\n", centimeters / cm2inch);
//    printf("%.2f\n", centimeters / defcm2inch);
   return (0);
   
}