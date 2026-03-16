#include<stdio.h>


int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void)
{
	int a = 10;                         // Initial value for a
	int b = 20;                          // Initial value for b
	int result = 0;                     // Storage for results
	// point to a function, so you can call its addess when you want to call it
    int (*pfunction)(int, int);              // Function pointer declaration

	pfunction = sum;                         // Points to function sum()
	result = pfunction(a, b);                // Call sum() through pointer
	printf("pfunction = sum result = %2d\n", result);

	pfunction = product;                     // Points to function product()
	result = pfunction(a, b);                // Call product() through pointer
	printf("pfunction = product result = %2d\n", result);

	pfunction = difference;                  // Points to function difference()
	result = pfunction(a, b);                // Call difference() through pointer
	printf("pfunction = difference result = %2d\n", result);

    // CAN USE IF/ELSE FOR IF (SOMETHING) use that fucntion eg product
    // else if (use that other function, difference
	return 0;
}
// there are a lot of fucntions that have a similar data structure
// so you can use the pointer to the 
int sum(int x, int y)
{
	return x + y;
}
int product(int x, int y)
{
	return x * y;
}
int difference(int x, int y)
{
	return x - y;
}