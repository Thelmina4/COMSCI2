/*
lab2-print-day.c
Author: Thelma Clarke
SID: 19746069
take in (an integer) and prints
the name of the day of the week to which it corresponds.
*/
#include<stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
   int length = 7;
   char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

   int day = atoi(argv[1]) -1;
   printf("%s\n", week[day]);
}
