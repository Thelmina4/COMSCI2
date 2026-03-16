/*
Author: Thelma
SID: 19746069

To practice with pointers and function pointers;

To become familiar with working with struct in C;

To use struct when designing a C program to solve some problems using C;

Note
DO NOT write EVERYTHING on the main function!

lab5-get-a-country.c

detail of a country from the command line as follows:
- Name - Capital - Population (in million) - Size (in km2)
The program can then print the information of the country 
line by line in the above order 

*/

// libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a country as a type name
typedef struct Country Country;


struct Country {
    /* data */
    char *country;
    char *capital;
    float pop;
    int size;
};


// Main Function
int main (int argc, char *argv[]) {
    // create an index to go through the command line
    int index = 1;
    // declare the variable type Country
    Country country1;
    country1.country = argv[index++];
    country1.capital = argv[index++];
    country1.pop = atof(argv[index++]);
    country1.size = atoi(argv[index++]);

    printf("%s\n", country1.country);
    printf("%s\n", country1.capital);
    printf("%.2f million people\n", country1.pop);
    printf("%d km2\n", country1.size);

    return 0;
}*/