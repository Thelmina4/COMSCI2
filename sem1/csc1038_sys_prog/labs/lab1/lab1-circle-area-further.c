/*
  circle-area-further.c
  Author: Thelma
  This time we need to see what we would do if a neg number is input
  do we
  1. correct the error 
  2. ask the user for a pos input

*/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

int main(int argc, char *argv[]){
    int radius1 = 0;
    int area1 = 0.0;
    radius1 = atoi(argv[1]);
    area1 = radius1*radius1;
    // printf("%d\n", radius1);
    printf("%d\n", area1);

    int radius2 = 0;
    int area2 = 0.0;
    radius2 = atoi(argv[1]);
    if (radius2 < 0){
       printf("A radius is a measurment of length.\nIt can't be a negative number.\n");
       printf("Please enter a number greater than 0: ");
       scanf("%d", &radius2);
    }
    area2 = radius2*radius2;
    // printf("%d\n", radius2);
    printf("%d\n", area2);
    return 0;
}
