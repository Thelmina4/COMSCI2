/*
lab2-count-odd-number.c
Author: Thelma Clarke 19746069
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   int length = 10; /* declare the length of array */
   int numbers[length];

   int odds = 0;
   for (int i = 0; i  < argc; ++i)
   {
      int num = atoi(argv[i]);
      // printf("%d", num);
      // printf("%d", atoi(argv[i+1]));
      // if (atoi(argv[i+1]) % 2 != 0){
      //    odds = odds + 1;
      // }
      if (num % 2 != 0)
      {
         odds++;
      }
   }
   printf("%d\n", odds);
   return (0);
}

