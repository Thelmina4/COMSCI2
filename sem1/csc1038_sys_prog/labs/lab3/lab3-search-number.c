/*
lab3-search-number.c
Author: Thelma Clarke
SID: 19746069

Search for a number & it's index in an array
find = argv[1]
array_numbers = argv[1:]
index_number = i at find[i]

input:
./lab3-search-number 4 9 12 5 7 8 4 13
output:
"Found 4 at 5"/ "Found %d at %d", find, i OR <value> not found
*/

/*Libraries*/
#include<stdio.h> // input output
#include<stdlib.h> // dealing w numbers
#include<stdbool.h> // for booleans

int main(int argc, char* argv[])
{
    int len_array = argc - 1;
    // printf("%d", argc);
    int find = atoi(argv[1]);
    bool found = false;
    int i = 2;
    int index;
    /*For loop to find the value & it's index*/
    for (i = 2; i <= len_array; i++)
    {
         
        /*if it's found save the value & index*/
        if (find == atoi(argv[i]))
        {
            // printf("%d\n", i);
            found = true;
            index = i-2;
        }
    }
    /*if found printf one thine, else print other*/
    if (found)
    {
        printf("Found %d at %d\n", find, index);
    }
    else
    {
        printf("%d not found\n", find);
    }
    
    return 0;
}
