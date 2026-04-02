#include<stdio.h>
#include<stdlib.h>

// layout2.c
// Memory Layout of a C Program

// uninitialised data
int x;
int a, b, c, d;
// initialised data
int y = 15;
int m = 1, n = 2;

int main(int argc, char *argv[]) {
    // *values and i go onto the stack
    int *values;
    int i;

    values = (int *)malloc(sizeof(int)*5);
    for(i = 0; i < 5; i++) values[i] = i;

    values[0] = values[1] + values[2];

    return 0;
}