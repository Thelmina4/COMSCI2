/*
Author: Thelma
SID: 19746069

To practice with pointers and function pointers;

To become familiar with working with struct in C;

To use struct when designing a C program to solve some problems using C;

Note
DO NOT write EVERYTHING on the main function!

lab5-average-population.c
List of countryies
detail of a country from the command line as follows:
- Name - Capital - Population (in million) - Size (in km2)
print everything in order separated by tabs \t\t\t
then the last line should be the total pop of all the countries

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

// prototype functions
void output(Country *countries, int count);

// Main Function
int main (int argc, char *argv[]) {

    // declare the variable type Country
    Country countries[50];

    // index to count the country number
    int times = argc / 4;
    // printf("%d", times);
    
    // create a variable to sum the population
    float sum = 0;

    // create an index to go through the command line
    int index = 1;
    for (int i = 0; i < times; i++) {
        
        countries[i].country= argv[index++];
        countries[i].capital = argv[index++];
        countries[i].pop = atof(argv[index++]);
        countries[i].size = atoi(argv[index++]); 
        // printf("%.2f\n",countries[i].pop);   
        // put this into the function
        sum += countries[i].pop;

    }
    output(countries, times);
    // printf("Population average: %.2f\n", sum/times);
    return 0;
}

void output(Country *countries, int count) {
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    float totalPop = 0;
    for (int i = 0; i < count; i++) {
        printf("%s\t\t\t", countries[i].country);
        printf("%s\t\t\t", countries[i].capital);
        printf("%d\t\t\t", countries[i].size);
        printf("%.2f\n", countries[i].pop);
        totalPop = totalPop + countries[i].pop;
    }
    printf("Population average: %.2f\n",totalPop/count);
}
