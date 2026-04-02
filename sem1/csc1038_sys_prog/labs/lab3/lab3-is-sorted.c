/* 
lab3-is-sorted.c
Author: Thelma CLarke
SID: 19746069

sorts an array of ints
outputs each sorted number, one per line

input: ./lab3-is-sorted 5 1 4 2 8
*/

/* libraries */
#include<stdio.h> // input output
#include<stdlib.h> // numbers atoi
/* possible functions */
void number_sort(int arr[], int size);

/* main function */
int main(int argc, char* argv[]) {
    /* Variables */
    int len_array = argc-1;
    int array_numbers[len_array];
    
    /* Turn argv into an array */
    int i = 0;
    for (i = 0; i < len_array; i++) {
        array_numbers[i] = atoi(argv[i+1]);
    }
    // printf("%d", i);

    // Sort the array
    number_sort(array_numbers, len_array);

    /* print the sorted array on new lines*/
    for (int i = 0; i < len_array; i++) {
        printf("%d\n", array_numbers[i]);
    }   
    return 0;
}
/* BUBBLE SORT */
void number_sort(int arr[], int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {   // Swap if out of order
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}