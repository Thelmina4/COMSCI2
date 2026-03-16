#include<stdio.h>

void doubleX(int *number);

int main(int argc, char * argv[])
{
	int number = 12;
    printf("%d\n", number);
    // inputting the address of the number
	doubleX(&number);
	printf("%d\n", number);
}
// the address was input, but using the variable stored there by using
// *number
void doubleX(int *number)
{
	// variable = variable * 2
    *number = *number*2;
}