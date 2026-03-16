#include<stdio.h>
#include<stdlib.h>

int sumOfArray(int* pNumbers, int length);
int productOfArray(int *pNumbers, int length);

int main(int argc, char*argv[]) {

    /* We need 10 integer numbers at the beginning */
    int capacity = 10;
    // capacity, and the type (eg, int)
    int *pNumber = calloc(capacity, sizeof(int));
    if (!pNumber) {
        printf("Failed\n");
    }
    for(int i = 0; i < 10; ++i)
    {
        *(pNumber + i) = i;
    }
    printf("Original data\n");
     for(int i = 0; i < capacity; ++i)
    {
        printf("%d ", *(pNumber + i));
    }
    printf("\n");
    /* Now we need to add more 5 numbers to the current working list */
    int *pTemp = NULL;
    int oldCapacity = capacity;
    capacity += 5;

    pTemp = realloc(pNumber, capacity*sizeof(int));
    if(!pTemp)
    {
        printf("Unfortunately memory reallocation failed.\n");
        free(pNumber);
        pNumber = NULL;
        return 0;
    }

    pNumber = pTemp;
    for(int i = oldCapacity; i < capacity; ++i)
    {
        *(pNumber + i) = i;
    }

    // after realloc
    printf("after realloc data\n");
     for(int i = 0; i < capacity; ++i)
    {
        printf("%d ",*(pNumber + i));
    }
}

