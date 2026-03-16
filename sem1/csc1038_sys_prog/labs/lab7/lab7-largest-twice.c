/*
Thelma Clarke
19746069

lab7-largest-twice.c

arguments from the command line. 

- accepts the list of INTS numbers.
- find the largest element which is at least 
- twice as much as at least one number in the array,
- print the result. 
- Otherwise the program prints 0. 
- Also note that you are required to find a way to use dynamic memory allocation,
- i.e. malloc, calloc, realloc and free in this task,

Input

./lab7-largest-twice 4 3 6 4 2
Output

6

plan: 
- assaign memory for array
- check allocated

- take in data into the array
- find max if even, find half

- start at the begining of array & see if half is there
- found
    return max max
- free up the memory

*/


// Libraries
#include<stdio.h>
#include<stdlib.h>

// prototype functions
// tester to see is memory allocated
void allocated(int *input);
// array for the numbers in command line
void array(int *pNumbers, char *argv[], int n);
// find the max number
int findMax(int *pNums, int n);

// function to find half of max
int half(int *pNums, int n, int max);

// main function
int main(int argc, char *argv[]) {
    // size of array
    int len_array = argc-1;

    // initialize to NULL
    int *pNumbers = NULL;
    pNumbers = malloc(len_array*(sizeof(int)));
    allocated(pNumbers);
    array(pNumbers, argv, len_array);
    int maxNo = findMax(pNumbers, len_array);
    // printf("max: %d\n", maxNo);
    printf("%d\n", half(pNumbers, len_array, maxNo));

    free(pNumbers);
    pNumbers = NULL;
    return 0;
}


// functions
void allocated(int *input) {
    // printf("Test that this is working");
    if (!input) {
        printf("The Memory was not allocated!\n");
    }
}

void array(int *pNumbers, char *argv[], int n) {
    for (int i = 0; i < n; i++) {
        *(pNumbers + i) = atoi(argv[i+1]);
        // printf("testing %d == %d\n", *(pNumbers + i), atoi(argv[i+1]));
    }
}

int findMax(int *pNums, int n) {
    int m = *(pNums);
    // return m;
    for (int i = 1; i < n; i++) {
        if (m < *(pNums+i)) {
            m = *(pNums+i);
        }
    }
    return m;
}

int half(int *pNums, int n, int max) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        // printf("max/2 %d\n", max/2);
        if (max/2 == *(pNums+i)) {
            found = max;
        }
    }
    return found;
}