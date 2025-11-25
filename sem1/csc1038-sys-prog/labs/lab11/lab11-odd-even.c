/*
Author: Thelma Clarke
SID: 19746069

file: 
lab11-odd-even.c
checks whether a given integer is odd or even
using bitwise operations only, i.e., 
no modulo (%), division, or arithmetic comparison operators

input:
 - ./lab11-odd-even 37
 - ./lab11-odd-even 18  

output:
Odd
Even

Plan:

*/

// libraries
#include<stdlib.h>
#include<stdio.h>

// function prototype
// if I add one to it and it was odd, I get an odd out, 
// if I add 1 and it was even I get 0 out.
// I don't know how, but it worked
int oddEven(char *argv[]);

// main function
int main(int argc, char *argv[]) {
    oddEven(argv);    
    return 0;
}
// function implementation
int oddEven(char *argv[])
{
    int bit = 1;
    int input = atoi(argv[1]);
    int output = input & bit;
    if (output) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
}
