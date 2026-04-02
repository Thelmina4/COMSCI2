/*
Author: Thelma
SID: 19746069

1. required to use the concept of pointers
2. required to solve all tasks given today using functions.
lab4-count-character.c

You can assume that the lowercase and uppercase of a character are two different cases,
e.g. C is not c. 
ount the number of occurences of the character in the string and print the result
input:
./lab4-count-character a "abcxyza"
output: 
2
*/

// Librabries used:
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// placeholder for functions
int count_letter(char *letters, char ch);

// main Function
int main(int argc, char *argv[]) {
    // pointer to the command line argv[1]
    char *letter = argv[1];
    // printf("argv[1] : %c \n\n", *letter);

    // pointer to the command line argv[2]
    char *word = argv[2];

    // input the array word 
    int result = count_letter(word, *letter);
    printf("%d\n", result);

    // make the function inside main to see if it works
    /*
    int count = 0;
    for(int i = 0; i < strlen(word); i++) {
        // printf("while loop to print each element in the array of argv[2] : %c \n", *(word+i));
        if (*letter == *(word+i)) {
            // printf("%c == %c\n", *letter, *(word+i));
            count++;
        }
    }
    printf("%d\n", count);
    */
    return 0;
}

// input the array using *
int count_letter(char *letters, char ch) {
    int count = 0;
    // printf("%d\n", strlen(letters));
    for(int i = 0; i <= strlen(letters); i++) {
        // letters[i] == *(letters+i)
        if (ch == letters[i]) {
            // printf("%c == %c\n", ch, *(letters+i));
            // if (letters[i] == *(letters+i)) {
            //     printf("letters[i] == *(letters+i)\n");
            // }
            count++;
        }
    }
    // printf("%d\n", count);
    return count;
}
