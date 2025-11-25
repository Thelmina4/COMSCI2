/*
Thelma Clarke
19746069

arguments from the command line. 

- accepts the list of floating numbers.
- find the second largest value in the array
- and print the result up to 1 digit after the decimal point.

- Note that there can be more than one largest or second-largest elements.
Input

./lab7-second-largest 5 3 6 3 4 5.4 7.2 7.2

Output

6

*/

// libraries
#include<stdio.h>
#include<stdlib.h>

// prototype functions
void allocated(float *input) ;
void array(float *pNumbers, char *argv[], int n);
void findLargest(float *array, int n);

// main function
int main(int argc, char * argv[]) {
    // size of array
    int n = argc - 1;

    // intitialize to Null
    float *pNumbers = NULL;
    pNumbers = malloc(n*(sizeof(float)));
    allocated(pNumbers);
    array(pNumbers, argv, n);
    findLargest(pNumbers, n);


    free(pNumbers);
    pNumbers = NULL;

    return 0;

}

//functions

void allocated(float *input) {
    if (!input) {
        printf("The memory was not allocated");
    }
    // printf("This function works\n");
}

void array(float *pNumbers, char *argv[], int n){
    for (int i = 0; i < n; i++) {
        *(pNumbers + i) = atof(argv[i + 1]);
        // printf("Testing: %f\n", *(pNumbers + i));
    }
}

void findLargest(float *array, int n){
    float largest, second = *(array);
    // printf("Second: %.1f\n", second);
    for (int i = 1; i < n; i ++) {
        if (*(array+i) > largest) {
            largest = *(array+i);
        }
    }
    // printf("%.1f\n", largest);
    for (int i = 1; i < n; i ++) {
        if (*(array+i) > second && *(array+i) < largest) {
            second = *(array+i);
        }
    }
    printf("%.1f\n", second);
}

