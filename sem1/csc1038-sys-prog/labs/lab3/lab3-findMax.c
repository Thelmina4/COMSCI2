/*
lab3-findMax.c
Author: Thelma Clarke
SID: 19746069

find the max of an array of nos from command line

input:
./lab3-findMax 4 9 12 5 7

output:
12

*/

// the libraries needed
// for the command lin, input output
#include<stdio.h>
/* As an experiment, I ran this without stdlib and it didnot work */
#include<stdlib.h>

/* Functions that I'll use */

// int findMax(int array_of_ints[len_array]);

int main(int argc, char* argv[])
{
    int len_array = argc;
    // printf("%d\n", argc);
    int findMax = atoi(argv[1]);
    for (int i = 2; i < len_array; i++)
    {
        int number = atoi(argv[i]);
        if (findMax < number)
        {
            findMax = number;
        }
    }
    printf("%d\n", findMax);
    return 0;
}
