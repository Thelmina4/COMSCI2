/*
Author: thelma Clarke
SID: 19746069

file:
lab10-load-binary.c

input: 
studentBinary.bin that contain information about a number of students
The 1st value in each block refers to the length of the student name

The 2nd value in each block refers to the student name

The 3rd value in each block refers to the length of the college

The 4th value in each block refers to the college name

The 5th value in each block refers to the age of the student (int)

The 6th value in each block refers to the grade of the student (float)

eg.
4 john
3 dcu
18
34.5

output:
Name: John
College: DCU
Age: 22
Grade: 87.50

Plan:
 - Make a file that I can turn into a binary file
 - Use that to then be able to read that file So that i can then make the code for the read binary
 - comment out my write binary section before uploading to einstein

 - possible functions
    - allocate
    - opened
    - writeBinary
    - readBinary
    - printBinary
*/

// libraries

#include<stdio.h>
#include<stdlib.h>
// don't need string, as working with binary
// #include<string.h>

// define a max string len so that the name/college is more than just 1 char

// Prototype functions
int opened(FILE *input, char *filename);

// convert binary 

void convertBinary(FILE *bin);

// main Functions
int main (int argc, char *argv[]) {

    // start with the reading from a normal text file
    // write that into binary to create the binary file that I need
    FILE *pfile = NULL;
    char *filename = "studentBinary.bin";
    pfile = fopen(filename, "r");
    opened(pfile, filename);
    convertBinary(pfile);

    return 0;
}

// implementation of the functions

void convertBinary(FILE *bin)
{
    // While loop to continue while there is still something to read in .bin
    while (1) {
        // make a variable for the len, name, age, grade
        int len, age;
        char name[256], college[256];
        float grade;

        // if there is nothing to read, break out of the loop
        if (fread(&len, sizeof(int), 1, bin) != 1) {
            break;
        }
        fread(name, sizeof(char), len, bin);
        name[len] = '\0';

        // read college len, make college[len]
        fread(&len, sizeof(int), 1, bin);
        fread(college, sizeof(char), len, bin);
        college[len] = '\0';

        // read age & grade
        fread(&age, sizeof(int), 1, bin);
        fread(&grade, sizeof(float), 1, bin);

        // print them all
        printf("Name: %s\n", name);
        printf("College: %s\n", college);
        printf("Age: %d\n", age);
        printf("Grade: %.2f\n", grade);
        
    }
    fclose(bin);
}

int opened(FILE *input, char *filename)
{
    if (!input) {
        perror("Failed to open file.\n");
    }
    else {
        // printf("File %s opened sucessfully\n", filename);
    }
    return 1;
}