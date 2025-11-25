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

int main(){
    /* 
        argc is a count of thhe command line args
        argv is a string, need to convert to int w atoi()
    */
    //    int cm2inch = 2.54;
    //    float centimeters = 0;
    //   printf("%d cm2inch, %f ", cm2inch, centimeters);
    //    printf("Please enter centimeters to be converted:\n");
    //    scanf("%f", &centimeters);
    //   scanf("%d", &radius2);
    // if I switch the int and floats, then the floats are rounded down
    // so if the input is 30. => 30.0\2=15.0

    //    printf("%d\n", centimeters);
    //    printf("%.2f\n", centimeters / cm2inch);
    //    printf("%.2f\n", centimeters / defcm2inch);

    float cm2inch = 2.54;
    int upper = 50;
    int lower = 30;
    float result0 = 0.0;
    float result1 = 0.0;
    float result2 = 0.0;
    float result3 = 0.0;
    float result4 = 0.0;

    for (int i = lower; i < upper; i+=5){

        result0 = i / cm2inch;
        result1 = (i+1)/ cm2inch;
        result2 = (i+2)/ cm2inch;
        result3 = (i+3)/ cm2inch;
        result4 = (i+4)/ cm2inch;
        // printf("%5.2f %10.2f %20.2f %5.2f %5.2f\n", result0, result1, result2, result3, result4);
        printf("%6.2f %6.2f %6.2f %6.2f %6.2f\n", result0, result1, result2, result3, result4);
    }
    return (0);
   
}