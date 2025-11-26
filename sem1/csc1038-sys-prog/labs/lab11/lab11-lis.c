/*
Author: Thelma Clarke
SID: 19746069

file:
lab11-lis.c
sequence of integers and finds the length of the longest increasing subsequence. 
input:
 - ./lab11-lis 10 9 2 5 3 7 101 18

output: 4
 - **Explanation: possible LIS: 2, 3, 7, 101
 
Known:
 -  accepts a sequence of integers
    (positive or negative) as command-line arguments.
 - A subsequence is a sequence derived by deleting zero or more elements 
 without changing the relative order. 
 
 - An increasing subsequence is one where each element is 
    strictly greater than the previous.

Plan:
make an arr for all of them
I'll need to make a list for the first one.
But what if the first one has multiple lists


*/

// libraries
#include<stdlib.h>
#include<stdio.h>

// function prototype
// make an array from the command line
int array(int n, char *argv[], int *arr);
void allocated(int *input);
void printArray(int *a, int n);

// lis function to find the longest sequence 
int longestSeq(int *arr, int n);

// main function
int main(int argc, char *argv[]) {
    int n = argc-1;
    if (n == 1){
        printf("0\n");
        return 0;
    }
    int *arr = (int *)malloc(n*sizeof(int));
    allocated(arr);
    array(n, argv, arr);
    // printArray(arr, argc-1);
    longestSeq(arr, n);
    // free the space up
    free(arr);
    return 0;
}

// function implementation
// confirm that that memory was allocated
int array(int n, char *argv[], int *arr)
{
    for (int i = 0; i< n; i++) {
        arr[i] = atoi(argv[i+1]);
        // printf("%d\n", arr[i]);
    }
}

void allocated(int *input)
{
    // printf("This function does not work\n");
    if (!input) {
        printf("The memory was not allocated\n");
    }
}
// for testing purposes
void printArray(int *a, int n)
{
    for (int i = 0; i< n;i++) {
        printf("%d\n", a[i]);
    }
}

int longestSeq(int *arr, int n)
{
    // no matter what the length will always be 1
    int gt = 1;
    for (int i = 0; i < n; i++) {
        int start = arr[i];
        int seq = 1;
        // start a new loop that is inside the first
        for (int j = i+1; j< n; j++) {
            if (arr[j] > start) {
                seq++;
                start = arr[j];
            }
        }
        // it has looped until j = n
        if (seq > gt) {
            gt = seq;
        }
    }
    printf("%d\n", gt);
}