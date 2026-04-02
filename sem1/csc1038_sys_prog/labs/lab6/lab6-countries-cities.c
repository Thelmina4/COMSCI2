/*
Author: Thelma Clarke
SID: 19746069

Lab 6
lab6-countries-cities.c

accepts input as the information of list of countries. 
Each country contain the following information:

    - Name of country
    - List of City

where City is also a structure which contain the following members:

    - Name
    - Size

The arguments include the following values: 
<country1> <city1> <size1> <city2> <size>2 <city3> <size3> <country2> … and so on

You can assume that we will enter 3 cities for each countries.
The program find the largest city of all countries and display the result.

Input:
./lab6-countries-cities Ireland Dublin 117.8 Cork 187 Galway 54.2 France Paris 105.4 Marseille 240.6 Lyon 47.87 Spain Madrid 604.3 Barcelona 101.4 Sevilla 140

OUtput:
Ireland: Cork
France: Marseille
Spain: Madrid

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct as type
typedef struct Country Country;
typedef struct City City;

// structs contain:
struct City {
    char *cityN;
    float size;
};
struct Country {
    char *name;
    City cities[3];
};

// prototype functions
// what do I need?
// 1. Country - get input
void getInput(Country *countries, int times, char *argv[]);
// 2. sort by coutry by largest city, output largest
void findLargest(Country *countries, int times);

// 3. print the full country & city list
void printFullOutput(Country *countries, int times);

// main function
int main(int argc, char *argv[]) {
    int times = argc/7;
    // printf("%d\n", times);

    Country countries[50];
    // int index = 1;

    // for (int i = 0; i < times; i++) {
    //     countries[i].name = argv[index++];
    //     for (int j = 0; j< 3; j++) {
    //         countries[i].cities[j].cityN = argv[index++];
    //         countries[i].cities[j].size = atof(argv[index++]);
    //     }    
    // }
    getInput(countries, times, argv);
    // printFullOutput(countries, times);
    findLargest(countries, times);
    return 0;
}

// functions used
void getInput(Country *countries, int times, char *argv[]) {
    int index = 1;

    for (int i = 0; i < times; i++) {
        countries[i].name = argv[index++];
        for (int j = 0; j< 3; j++) {
            countries[i].cities[j].cityN = argv[index++];
            countries[i].cities[j].size = atof(argv[index++]);
        }    
    }
}

void findLargest(Country *countries, int times) {
    // float biggest;
    // int col;
    // looking within the country
    // for loop for the country,
    // set biggest to the first size, if cities[j].size is bigger
    // biggest =  cities[j].size
    // col = j
    // printf countries[i].name: countries[i].cities[col].cityN
    for (int i = 0; i < times; i++) {
        float big = countries[i].cities[0].size;
        // printf("%.2f\n", big);
        int col = 0;
        for (int j = 1; j < 3; j++) {
            if (countries[i].cities[j].size > big) {
                big = countries[i].cities[j].size;
                col = j;
            }
        }
        printf("%s: %s\n", countries[i].name, countries[i].cities[col].cityN);
    }
}

void printFullOutput(Country *countries, int times) {
    for (int i=0; i < times; i++) {
        printf("%s\n",countries[i].name);
        for (int j = 0; j < 3; j++) {
            printf("City: %s\nSize: %.2f\n", countries[i].cities[j].cityN, countries[i].cities[j].size );
        }
    }
}
