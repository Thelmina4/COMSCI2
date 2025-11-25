/*
Author: Thelma Clarke
SID: 19746069

file:
lab11-climb-stairs.c
You are climbing a staircase. 
It takes n` steps to reach the top. 
Each time you can either climb 1 step or 2 steps. 

calculates how many distinct ways you can climb to the top. 
Try to use dynamic programming.

input:
./lab11-climb-stairs.c 2
 - **Explanation: You can climb:
    1 step + 1 step / or

    2 steps 
output:2 

**input
./lab11-climb-stairs.c 4
**output:
5
**Explanation: You can climb:

    1+1+1+1 or

    1+2+1 or

    2+1+1 or

    1+1+2 or

    2+2

Total of 5 distinct ways.
Plan:
Draw it out
if there is one step x = 1, i = 0, x = x + i
if there is 2 steps x = 1, i = 1, x = x + 1 = 2

*/

// libraries
#include<stdlib.h>
#include<stdio.h>
// structs

// function prototype
int stairs(int x);
// main function
int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);
    stairs(x);
    
    return 0;
}
// function implementation
int stairs(int x) 
{
    int result = 2;
    if (x == 0){
        printf("0\n");
        return 0;
    }
        if (x == 1){
        printf("1\n");
        return 0;

    }
    int i = 0;
    for (int j = 1; j<x;j++) {

        result += i;
        i++;
    }
    printf("%d\n", result);
}

