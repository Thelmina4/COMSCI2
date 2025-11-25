#include<stdio.h>
#include<stdlib.h>


int main(int argc, char*argv[])
{
	int length = argc - 1; /* Utilise the value of argc in the main function. argc = number of arguments. Remember the first argument is the program name, so the number of actual arguments we will process is argc - 1 */
	int grades[length]; /* declare the array */
	int sum = 0; /* initialise the sum of grade = 0 */
	float average = 0;  /* beware of data type here, average should be float  */

	/* read the input and calculate the sum of grades */
	for(unsigned int i = 0; i < length; ++i)
	{
		/* note that argv[0] = the program name, so we only take the values from argv[1] and so on. On the other hand, we start i = 0 because we want to assign value from grades[0] and so on. So this is the way we solve the problem: ?*/
		grades[i] = atoi(argv[i+1]);

		/* Calculate the sum of grades continously */
		sum += grades[i];
	}

	/* calculate the average */
	average = (float)sum/length; /* convert sum from integer to float before calculating, to make sure that average is a float number */

	/*print out the grades line by line */
	for(unsigned int i = 0; i< length; ++i)
	{
		/* Although the index of array start from zero, it is abit weird to print out Student 0. We one it will be printed from 1. So we need to print out i+1 */
		printf("Student %d : %d\n", i+1, grades[i]);
	}

	/*print out the average */
	printf("The average of the %d grades is: %f\n", length, average);

	return(0);
}