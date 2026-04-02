/*
lab2-find-even-number.c
Author: Thelma Clarke 19746069

find all even elements in an array of integers.

Output: In each line, print out the result as follows:
<index> - <value>. If there is no even number,
print out "Not found!" followed by a new line character.

max length of the array is 10. 

./lab2-find-even-number 3 5 12 43 4 2 5
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   int length = 10;
   int array[length];

   // char notfound = ("Not found!\n");
   int count = 0;
   for (int i =1; i < argc; i++)
   {
      int num = atoi(argv[i]);
      // printf("%d\n", num);
      if (num % 2 == 0)
      {
         printf("%d - %d\n", i-1, num);
         count++;
      }

   }
   if (count == 0)
   {
      printf("Not found!\n");
   }
   return (0);

}