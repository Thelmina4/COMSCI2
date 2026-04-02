#include<stdio.h>
#include<stdlib.h> // for the malloc function

int main(int argc, char * argv[]) {

    // want an array of ints
    int a[4]; // array of 4 ints

    // int * at malloc is optional
    // in this example, we ahve req 200 bytes of memory and assigned an address to this block of memory

    int *pNumber = (int*)malloc(200);
    // the above line is equivalent to the line below
    int *pNumber = (int*)malloc(50*sizeof(int));

    // it the malloc function can return you a block of memory it will return the block else it will return null
    if(!pNumber)
    {
        //... Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
    }

    // free up the space of the memory that you no longer need
    free(pNumber); // release the memory
    pNumber = NULL;

    printf();
    return 0;
}