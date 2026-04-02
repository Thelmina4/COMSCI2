/*
lab3-duplicated-number.c
Author: Thelma Clarke
SID: 17946069

input an int array from command line
./lab3-duplicated-number 4 9 12 5 7 8 4 13

outputs a duplicated number if it finds one
or
no duplicated number\n
*/
/*Libraries needed*/
#include<stdio.h> // input output
#include<stdlib.h> // numbers
#include <stdbool.h> // booleans

/* Functions needed */

// int seen();

/* Main Function */
int main(int argc, char* argv[])
{
    // variables
    int len_array = argc;
    bool found = false;
    int dup;
    /* presume that it's at the first position
    2 x for loops until you find it */
    int i;
    int j;
    for (i = 1; i < len_array; i++)
    {
        for(j = i + 1; j < len_array; j++)
        {
            if (atoi(argv[i]) == atoi(argv[j]) && found == false)
            {
                found = true;
                dup = atoi(argv[i]);
            }
        }
    }
    /*if found printf one then, else print other*/
    if (found)
    {
        printf("%d\n", dup);
    }
    else
    {
        printf("no duplicated number\n");
    }
    
    return 0;
}




