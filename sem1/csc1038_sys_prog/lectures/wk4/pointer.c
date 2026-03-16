/*
Start from the begining
how to make a pointer from a new variable

*/

#include<stdio.h>

int main() {
    int number = 99;
    printf("This is just the number, use percent d: %d\n", number);

    // the address of the number is at & number: %d\nThe address is an int, so use percentage d
    printf("the address of the number is at & number: %d\nThe address is an int, so use percentage d\n", &number);
    
    int *pnumber = &number;          // creating a pointer to the address of the number
    printf("What do I get with pnumber: %d\n", pnumber);
    printf("It's the address of the number, i used percentage d \n");
    printf("What do I get with percent p pnumber: %p\n", pnumber);
    // printf("What do I get with %p", *pnumber);

    int num = 15;
    int *pointer = &num;
    int result = 0;

    /*access the value of pointer and calculate the new value for result */
    result = *pointer + 1;
    printf("result: %d\n\n", result);
    return 0;
}