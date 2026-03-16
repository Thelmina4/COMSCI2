#include<stdio.h>

int main(int argc, char * argv[]) {
    int inputArray[3] = {1, 2, 3};

    int *pFirstElement = &inputArray[0];

    printf("How to find the values in the array using pointers\n\n");
    printf("Value 1, %%d *pFirstElement: %d\n", *pFirstElement);
    printf("Value 2, %%d *(pFirstElement+1): %d\n", *(pFirstElement+1));
    printf("Value 3, %%d *(pFirstElement+2): %d\n\b", *(pFirstElement+2));

    printf("The addresses of the elements:\n");
    printf("Address of the first element %%p pFirstElement:  %p\n", pFirstElement);
    printf("Address of the second element %%p (pFirstElement+1): %p\n", (pFirstElement+1));
    printf("Address of the third element %%p (pFirstElement+1):  %p\n", (pFirstElement+2));

    #include<stdio.h>


	int numbers[] = {1L, 2L, 3L , 4L}; /* declare an array with type long */
	int *pNumber = numbers; /* point the pNumber to the first byte of the array */

	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); ++i)
	{
		printf("address pNumber + %d or &numbers[%d] is: %llu\n", i,i, (unsigned long long)(pNumber+i)); /* convert the address to a positive large number */
		printf("value *(pNumber+ %d) is: %d\n", i, *(pNumber+i));
	}

   
   
    return 0;

}