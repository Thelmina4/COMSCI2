/*
lab3-calculator.c
Author: Thelma Clarke
SID: 19746069
calculate product or division
one function for product
one function for division

remember to use comments along the way

usage:
./lab3-calculator multiply 5.2 4.6
./lab3-calculator divide 12.1 0
*/

// std input output
#include<stdio.h>
// provides memory allocation,generating random numbers
#include<stdlib.h>
// As it's needed for manipulating strings (arrays of characters)
#include<string.h>

/*Function prototypes, the functions that I need to use*/
double product(double x, double y);
double division(double x, double y);

// take info fromt he command line
// main function
int main(int argc, char* argv[])
{
    // list the variables that I need
    char* line;
    line = argv[1];
    // printf("%s\n", argv[1]);
    double x = atof(argv[2]);
    double y = atof(argv[3]);
    // printf("%f", x*y);

    // printf("x = %f\ny=%f\n", x, y);
    double prod;
    double div;

    // input the variables through the functions
    // don't have to declare it's type here as it is declared in the function
    if (x == 0 || y == 0)
    {
        printf("invalid\n");
    }
    else
    {
        if (strcmp(line, "multiply") == 0)
        {
            prod = product(x, y);
            printf("%f\n", prod);
        }
        else{
            div = division(x, y);
            printf("%f\n", div);
        }
    
    }

    return 0;
}

// place the functions outside the main function
double product(double x, double y)
{
    double prod = x * y;
    return prod;
}

double division(double x, double y)
{
    double div = x / y;
    return div;
}
