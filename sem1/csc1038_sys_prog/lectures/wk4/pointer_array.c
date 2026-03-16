#include<stdio.h>

int main() {
    int inputArray[3] = {1, 2, 3};
    // pointer to the address of the first element in the array
    int *pFirstElement = &inputArray[0];

    printf("Theaddress of the first element is, %%p pFirstElemnet: %p\n", pFirstElement);

    printf("The address obtained from the array name using %%p %p:  \n", inputArray);

    printf("the value of the first element is %%d : %d * pfirstElement\n", *pFirstElement);
    
    
    
    
    
    
    return 0;
}