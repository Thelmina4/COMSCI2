/*
Author: Thelma
SID: 19746069

To practice with pointers and function pointers;

To become familiar with working with struct in C;

To use struct when designing a C program to solve some problems using C;

Note
DO NOT write EVERYTHING on the main function!

lab5-sort-numbers.c
input:
sorts an array of integers using different sorting orders (ascending or descending)
./lab5-sort-numbers 5 42 23 56 15 8 asc

The number of integers (an integer)

A list of integers

The sorting order (asc for ascending or desc for descending)

output; Sorted numbers: 8 15 23 42 56

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// functions
void sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i- 1; j++) {
            if (arr[j] > arr[j +1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                // printf("hi");
            }
        }
    }
}

// main function
int main (int argc, char *argv[]) {
    int a = 6;
    int *pA = &a;

    // printf("The variable: %d\n", a);
    // printf("The variable using the pointer: %d\n", *pA);

    // printf("The address : %p\n", &a);
    // printf("The address using pointer: %p\n", pA);
    int count = atoi(argv[1]);
    // printf("count: %d\n", count);

    int num[count];
    for (int i = 0; i < count; i++) {
        num[i] = atoi(argv[i+2]);
    }
    // check that the array is correct
    // for (int i = 0; i < count; i++) {
    //    printf("i : %d num: %d\n", i, num[i]);
    // }
    // printf("\n");

    char *order = argv[count+2];

    // printf("%s\n", order);

    // compare to see if asc or desc
    int asc = 0;
    if (strcmp(order, "asc") == 0) {
        asc = 1;
    }
    else if (strcmp(order, "desc") == 0) {
        asc = -1;
    }
    // printf("%d\n", asc);
    // printf("\n");

    // if it is > 0 then do the asc function
    // else if it is < 0  do the desc fucntion

    // call the sorting function
    // input - pointer to the array of nums
    //       - len of array
    sort(num, count);

    // print out the sorted numbers in the correct order
    printf("Sorted numbers: ");
    if (asc > 0) {
        int i = 0;
        for (i = 0; i < count-1; i++) {
            printf("%d ", num[i]);
        }
        printf("%d", num[i]);

    }
    else if (asc < 0) {
        int i = 0;
        for (i = 0; i < count-1; i++) {
            printf("%d ", num[count-i-1]);
        }
        printf("%d", num[count-i-1]);

    }
    printf("\n");
    return 0;

}