/*
Author: Thelma Clarke
SID: 19746069
lab3-leap-year.c

input: ./lab3-leap-year 2008 2020

Prints out all leap years between the first number 
and the second number inclusive.

They should be printed one per line.
minimum year which should be considered is 1582 CE, 
and the maximum is 2020 CE.

(ly % 4 == 0 && ly % 100 != 0) || ly % 400 == 0
*/

// libraries
#include<stdio.h>   // input out
#include<stdlib.h>  // numbers in input

// functions
void leapYear(int start, int end)
{
    for (int i = start; i < end+1; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            printf("%d\n", i);
        }
    }

}

// main function
int main(int argc, char *argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    // printf("start: %d\nend: %d", start, end);
    leapYear(start, end);

    return 0;
}