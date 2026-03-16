/*
lab3-string-reverse.c
Author: Thelma Clarke
SID: 19746069

reverse a given string. 

remember to use comments along the way

usage:
./lab3-string-reverse "to be or not to be"
output:
eb ot ton ro eb ot
*/

// std input output
#include<stdio.h>
// provides memory allocation, generating random numbers
// #include<stdlib.h>
// As it's needed for manipulating strings (arrays of characters)
// check what type of calculation (multiply or divide) we need to call.
#include<string.h>

/*Function prototypes, the functions that I need to use*/
char reverse(char line[50]);

// main function
int main(int argc, char* argv[])
{
    // declare the variables needed
    char* line = argv[1];
    // printf("%s\n", line);
    char rev_line;

    // call the reverse function
    rev_line = reverse(line);
    // int string_len = strlen(line);
    // printf("%d\n", string_len);
    
    return 0;
}

char reverse(char line[50]){
    int string_len = strlen(line);
    // printf("%d\n",string_len);

    for (int i = (string_len -1); i >= 0; i--)
    {
        printf("%c", line[i]);
    }
    printf("\n");

}
