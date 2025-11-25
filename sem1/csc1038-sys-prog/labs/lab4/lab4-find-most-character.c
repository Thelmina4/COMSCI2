/*
Author: Thelma Clarke
SID: 19746069
1. required to use the concept of pointers: Done
2. required to solve all tasks given today using functions: Done
lab4-find-most-character.c
*/

// libraries used
#include<stdio.h>
#include<string.h>
// for isalpha
#include<ctype.h>

// placeholder for the functions used
char findChar(char *line);

// main function
int main(int argc, char *argv[]) {

    // pointer to the first char in array from arv[1]
    char *pline = argv[1];
    char result;
    for (int i = 0; i < strlen(pline); i++) {
        result = findChar(pline);
    }
    // printf("ascii to *pline: %d\n", *pline);
    // printf("strlen(pline): %d\n", strlen(pline));
    // printf("\n");
    // use the function inside the main function

    // char result = findChar(pline);
    printf("%c\n", result);

    return 0;
}

char findChar(char *line) {
    
    char max_char;
    int max_count = 0;
    for (int i = 0; i < strlen(line); i++) {
        char ch = line[i];
        // printf("%c\n", ch);
        int count = 1;
        for (int j = i+1; j < strlen(line); j++) {
            // printf("%c, %c\n", ch, pline[j]);
            // only want isalpha
            if (ch == line[j]) {
                // printf("%c == %c\n", ch, pline[j]);
                count++;
            }           
        }
        if (count > max_count && isalpha(ch)) {
            max_count = count;
            max_char = ch;
            // printf("%c", max_char);
        }
    }
    // printf("%d, %c\n", max_count, max_char);
    return max_char;
}