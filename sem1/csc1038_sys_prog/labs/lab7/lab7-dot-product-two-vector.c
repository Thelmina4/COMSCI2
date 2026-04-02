/*
Thelma Clarke
19746069

arguments from the command line. 

First argument is the size of two vectors n.
The next n arguments are the elements of vector 1,
and the last n arguments are the elements of vector 2.
The program calculate the dot product of the two vectors and print the result.
Note that you are required to find a way to use dynamic memory allocation,
i.e. malloc, calloc, realloc and free in this task,
also you are encouraged to use function to design the solution.

Input

./lab7-dot-product-two-vector 3 1 2 3 4 -5 6
Output

12

*/

#include<stdio.h>
#include<stdlib.h>

int dotProduct(int *pV1, int *pV2, int n);

int main(int argc, char *argv[]) {
    // creat the size of the vectors
    int n = atoi(argv[1]);
    // pinitiaize the vectors to NULL
    int *pV1 = NULL;
    int *pV2 = NULL;

    // test that the memory was allocated
    pV1 = (int*)malloc(n*(sizeof(int)));
    if (!pV1) {
        printf("V1 failed to allocate memory");
        return 0;
    }

    pV2 = (int*)malloc(n*(sizeof(int)));
    if (!pV2) {
        printf("V2 failed to allocate memory");
        return 0;
    }
    
    // input the data in to the 2 vectors
    int index = 2;

    for (int i = 0; i < n; i++) {
        *(pV1 + i) = atoi(argv[index++]);
    }
    
    for (int i = 0; i < n; i++) {
        *(pV2 + i) = atoi(argv[index++]);
    }
    
    dotProduct(pV1, pV2, n);

    free(pV1);
    free(pV2);
    pV1 = NULL;
    pV2 = NULL;

    return 0;
}

int dotProduct(int *pV1, int *pV2, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += pV1[i] * pV2[i];
    }
    printf("%d\n", result);
}