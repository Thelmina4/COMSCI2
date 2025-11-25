/*
Author: Thelma
SID: 19746069

To practice with pointers and function pointers;

To become familiar with working with struct in C;

To use struct when designing a C program to solve some problems using C;

Note
DO NOT write EVERYTHING on the main function!

input:
./lab6-find-country Ireland Dublin 4.99 84421 Germany Berlin 83.24 357386 France Paris 67.39 632734
output;
The program find all countries whose size is smaller than 100000 km2 and print the result.

Country			Capital			Size			Population
Ireland			Dublin			84421			4.99

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<math.h>

// structs
// define the struct type Country as a type name
typedef struct Country Country;

struct Country {
    // initialise the varables for the country
    // it's coming in from command line, so need to convert pointers
    char *name;
    char *capital;
    int size;
    float pop;

};

// prototype functions
void sortsize(Country *countries, int x);

void sortpop(Country *countries, int x){
    for (int i = 0; i < x-1; i++) {
        for (int j = 0; j < x - i - 1; j++){
            // printf("i : %.2f  , i-1: %.2f\n", countries[i].pop, countries[i-1].pop);
            if (countries[j].pop < countries[j+1].pop) {
                Country tmp = countries[j];
                countries[j] = countries[j+1];
                countries[j+1] = tmp;
            }
        }
    }
}

void printout(Country *countries, int x){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < x; i++) {

        printf("%s\t\t\t", countries[i].name);
        printf("%s\t\t\t", countries[i].capital);
        printf("%d\t\t\t", countries[i].size);
        printf("%.2f\n", countries[i].pop);
    }
}

// Main Function
int main(int argc, char * argv[]) {

    int tabs2spaces = strlen("                 ");
    // printf("tabs2spaces: %d\n", tabs2spaces);
    // initialise the type Country to varable countries
    // can input up to 50 countries in the list
    Country countries[50];

    // need to go through argv x amount of times
    int x = argc/4;

    int index = 1;
    for (int i = 0; i < x; i++) {
        countries[i].name = argv[index++];
        countries[i].capital = argv[index++];
        countries[i].pop = atof(argv[index++]);
        countries[i].size = atoi(argv[index++]);
    }

    // print out the first line
    int this = strlen("Country			"); // with tabs
    int n = strlen("Country         ");
    // printf("total strlen: %d\nstrlen - strlen(country): %d\n", n, n-7);

    // sortsize(countries, x);
    sortpop(countries,  x);

    printout(countries, x);

    return 0;
}

// functions used
void sortsize(Country *countries, int x){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < x; i++) {
        int maxsize = 100000;
        // printf("%d\n", countries[i].size);

        if (countries[i].size < maxsize){
            // printf("%-24s", countries[i].name);
            // printf("%-24s", countries[i].capital);
            // printf("%-24d", countries[i].size);
            // printf("%-24.2f\n", countries[i].pop);
            printf("%s\t\t\t", countries[i].name);
            printf("%s\t\t\t", countries[i].capital);
            printf("%d\t\t\t", countries[i].size);
            printf("%.2f\n", countries[i].pop);
        }
    }
}
