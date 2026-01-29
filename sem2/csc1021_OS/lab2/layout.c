#include<stdio.h>
#include<stdlib.h>

// layout.c
// Memory Layout of a C Program

// uninitialised data
int x;
// initialised data
int y = 15;

int main(int argc, char *argv[]) {
    // *values and i go onto the stack
    int *values;
    int i;

    values = (int *)malloc(sizeof(int)*5);
    for(i = 0; i < 5; i++) values[i] = i;

    return 0;
}