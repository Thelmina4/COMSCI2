/*
Name: Thelma Clarke
SID: 19746069
Date 27.28.2025

file: ex2-merge-sorted.c

Task: MERGE 2 sorted arrays. 

Input: ./ex2-merge-sorted 4 1 3 5 7 3 2 4 8

Output: one int per line
1
2
3
4
5
7
8
Plan:

Put the first n digits into an array

make functions for 
 - allocated
 - merge the sorted arrays
 - print the last array

free the memory
*/

// libraries
#include<stdio.h>
#include<stdlib.h>

// prototype Functions
// to confirm that the memory has been allocated for the array
void allocated(int *input);
// create merged array - 
int *merge(int *arrOne, int *arrTwo, int n, int m);
// Print array
void printInt(int *array, int c);
// ####################################################
// main Function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }
    // make the variables for the len of the 2 input arrays
    int n = atoi(argv[1]);
    int m = atoi(argv[n +2]);
    // make the arrays and check that their memories are allocated
    int *arrOne = (int*)malloc(n*sizeof(int));
    allocated(arrOne);
    for (int i = 0; i< n; i++) {
        arrOne[i] = atoi(argv[i+2]);
    }
    int *arrTwo = malloc(m*sizeof(int));
    allocated(arrOne);
    for (int i = 0; i< m; i++) {
        arrTwo[i] = atoi(argv[i+3 + n]);
    }
    // uncomment the next 2 lines to confrim that the arrays are correctly created
    // printInt(arrOne, n);
    // printInt(arrTwo, m);

    // Make the new array and check memosy is allocated
    // len new aRR = n + m
    // input the data for the merged array
    int *arrThree = merge(arrOne, arrTwo, n, m);
    printInt(arrThree, n+m);

    // free the memory for the arrays up
    free(arrOne);
    free(arrTwo);
    free(arrThree);
    // printf("%d %d\n", n, m);
    return 0;
}
// ####################################################

// implemented Functions
void allocated(int *input)
{
    if (!input) {
        printf("The Memory was not allocated\n");
    }
}
void printInt(int *array, int c) {
    for (int i = 0; i <c; i++) printf("%d\n", array[i]);
}
int *merge(int *arrOne, int *arrTwo, int n, int m)
{
    int *arrThree = malloc((n+m)*sizeof(int));

    // len new arr = n+m
    int r = 0;
    int i = 0;
    int j = 0;
    while (r < n+m ) {
        while (i < n && j < m) {
            if (arrOne[i] < arrTwo[j]) {
                arrThree[r] = arrOne[i];
                // printf("arr3: %d\n", arrThree[r]);
                i++;
                r++;
            } else if  (arrOne[i] > arrTwo[j])  {
                arrThree[r] = arrTwo[j];
                // printf("arr3: %d\n", arrThree[r]);
                j++;
                r++;
            }
        }
        // printf("%d , %d \n", arrOne[j], )
        if ( i == n && j < m) {
            arrThree[r] = arrTwo[j];
            j++;
            r++;
        } else {
            arrThree[r] = arrOne[i];
            i++;
            r++; 
        }
    }
    return arrThree;
}
