/*
Author: thelma Clarke
SID: 19746069
file: lab10-longest-line.c

input: 
 - Given a text file paragraph.txt
 - contain a paragraph extracted from news on the Internet.
 - In the file, each line contains a sentence of the paragraph.
 - read the data from the text file paragraph.txt
 - The program then finds the longest sentence in the paragraph
 - The program displays:
    - the length of the sentence in the first line
    - and the sentence in the second line.
 -  assume that the maximum length of each sentence is 200

 output:
50
the sentence of 50 chars

Plan:
read the text & make array of the lengths
 - rewind
 - return the array
find the max of the array
 - return it's index

run through the .txt again
 - return the string of length / of index

print
 - len
 - string

OR - make 2 arrays at the begining? one for len one for string?
OR - struct w variables string, string_len
OR - find the strlen for each line, return the max, rewind,
    - if strlen == other_strlen print

*/

// libraries

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// max max 200 it works for the
//  str len and the number of lines to read in paragraph
#define MAX 200

// type structs 
typedef struct Longest Longest;
struct Longest {
    char *sentence[MAX];
    int len_sentence;
};

// Prototype functions
int opened(FILE *pfile, char *filename);

void longestLine(FILE *txt);
// main Functions
int main (int argc, char *aargv[]) {

    FILE *pfile = NULL;
    char *filename = "paragraph.txt";
    pfile = fopen(filename, "r");
    opened(pfile, filename);
    longestLine(pfile);

    fclose(pfile);
    return 0;
}

// implementation of the functions

// is the file opened
int opened(FILE *pfile, char *filename) {
    if (!pfile) {
        printf("File %s was not opened\n", filename);
    }
    // else printf("file %s was opened\n", filename);
}

void longestLine(FILE *txt)
{
    int maxLine = 0;
    char outputline[MAX] = {0};
    char txt_string[MAX];

    while (fgets(txt_string, sizeof(txt_string), txt)) {

        int str_len = strlen(txt_string);

        if (str_len > maxLine) {
            maxLine = str_len;
            // printf("%d", maxLine);
            strcpy(outputline, txt_string);
        }
    }
    printf("%d\n%s\n", maxLine, outputline);
}