/*
Author: Thelma
SID: 19746069

To practice with pointers and function pointers;

To become familiar with working with struct in C;

To use struct when designing a C program to solve some problems using C;

Note
DO NOT write EVERYTHING on the main function!

lab5-cal-everything.c

input:
./lab5-cal-everything 10 2
accepts two non-zero interger numbers a and b

Keep two digits after the decimal point.

You may need the library math.h to solve this task
and add -lm flag to link the math library to your executable: 
gcc -o my_program my_program.c -lm.

log() for natural logarithms and log10() for base-10 logarithms.

You need to find a way to use function pointer instead of just calling every function.

Output:

12.00
8.00
20.00
5.00
100.00
3.00

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// prototype functions
float sum(float *a, float *b);
float difference(float *a, float *b);
float product(float *a, float *b);
float division(float *a, float *b);
float power(float *a, float *b);
float logn(float *a, float *b);

// Main Function
int main(int argc, char *argv[]) {
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    // printf("%.2f %f\n", a, b);
    // printf("%p %p\n", &a, &b);
  
    sum(&a, &b);
    difference(&a, &b);
    product(&a, &b);
    division(&a, &b);
    power(&a, &b);
    logn(&a, &b);

    return 0;
}


// functions used

float sum(float *a, float *b) {
    // printf("%p %p\n", &a , &b);  // this is the address
    printf("%.2f\n", *a + *b);  // this is the value

}

float difference(float *a, float *b) {
    printf("%.2f\n", *a - *b);  // this is the value

}
float product(float *a, float *b) {
    printf("%.2f\n", *a * *b);  // this is the value

}
float division(float *a, float *b) {
    printf("%.2f\n", *a / *b);  // this is the value

}
float power(float *a, float *b) {
    printf("%.2f\n", pow(*a, *b));  // this is the value

}
float logn(float *a, float *b) {
    printf("%.2f\n", log(*a) + log(*b));  // this is the value

}

