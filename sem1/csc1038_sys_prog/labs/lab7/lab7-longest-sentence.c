#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Thelma Clarke
19746069

accepts a number of strings. 
The program finds and prints the longest string(s) 
line by line. 
Note that there can be more than one longest strings. 

Note that you are required to find a way to use dynamic memory allocation,
 i.e. malloc, calloc, realloc and free in this task, 
 also you are encouraged to use function to design the solution.

Input

./lab7-longest-sentence afdasg fhdfgh tyuiop fds sa
Output

fhdfgh
tyuiop

plan:
make the array (remember that they are already pointers)

set max len to the first string
for loop to find max len

if a string has max len print it
*/

// prototypes
void allocated(char *input);

// find the max len of the command line
void max_string(int n, char *argv[]) {
   int max_len = strlen(argv[1]);
   // printf("Max len: %d\n", max_len);
   for (int i = 1; i < n; i++) {
      // printf("hi string: %s\n", argv[i+1]);
      if (strlen(argv[i+1]) > max_len) {
         max_len = strlen(argv[i+1]);
      }
   }
   // printf("max_len %d", max_len);
   for (int i = 0; i < n; i++) {
      // printf("%s\n", argv[i+1]);
      if (max_len == strlen(argv[i+1])) {
         printf("%s\n", argv[i+1]);
      }
   }
}

// print out the string of that len

// main 
int main(int argc, char *argv[]) {
   int n = argc-1;
   char *pString = malloc(n*sizeof(char));
   allocated(pString);

   max_string(n, argv);


   free(pString);
   pString = NULL;
   return 0;
}

// running functions
void allocated(char *input) {
   // printf("Testing allocated function");
   if (!input) {
      printf("Warning: no memory allocated\n");
   }
}