#include<stdio.h>

int main() {
    int inputArray[3] = {1, 2, 3};

    int *pFirstElement = &inputArray[0];

    printf("The address of the first element 3 ways\n");
    printf("Using %%p &inputArray:   %p\n", &inputArray);

    printf("Using %%p inputArray:    %p\n", inputArray);

    printf("Using %%p pFirstElement: %p\n", pFirstElement);

    return 0;
}