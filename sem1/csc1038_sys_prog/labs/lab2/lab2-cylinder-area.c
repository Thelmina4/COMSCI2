/*
lab2-cylinder-area.c
Author: Thelma Clarke 19746069
*/
/*
trouble shooting
If there is no input argument, print out: "No input given!"

If there is only one argument, print out: "Two arguments needed!"

If a negative number is given, print out: "The radious or height cannot be negative!"

Otherwise, print out the area of the Cylinder. Do some research if you want to check again how to calculate it.

Remember to add a newline character \n at the end.
*/
#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[]){
    // first argv[1] == radius
    // argv[2] == heigth

    int radius = 0;
    int height = 0;   
    if (argc < 2){
        printf("No input given!\n");
    }
    else if (argc < 3){
        printf("Two arguments needed!\n");
    }
    else if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0){
        printf("The radius or height cannot be negative!\n");

    }
    else {
        radius = atoi(argv[1]);
        height = atoi(argv[2]);     
    }
    // printf("%d, %d\n", radius, height);
    printf("%.2f\n", (2 * PI * radius * height) + (2 * PI * radius * radius));

    // int radius = atoi(argv[1]);
    // int height = atoi(argv[2]);

    // area of a cylinder: A = (2 * PI * radius * heigth) + (2 * PI * radius * radius)

    return (0);

}