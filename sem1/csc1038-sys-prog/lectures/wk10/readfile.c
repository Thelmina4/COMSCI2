/* import libraries */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main(int argc, char*argv[])
{
    char name[MAX];
    char college[MAX];
    int age;
    float grade;

    FILE *pfile = NULL;
    char *filename = "data.txt";
    pfile = fopen(filename, "r");
    if(!pfile)  // Open myfile.txt to write it
        printf("Failed to open %s.\n", filename);

    fgets(name, MAX, pfile);
    fgets(college, MAX, pfile);
    fscanf(pfile, "%d", &age);
    fscanf(pfile, "%f", &grade);

    fclose(pfile);

    printf("Name: %s", name); /*Note that there is a newline character at the end of the line in the file already */
    printf("College: %s", college);
    printf("Age: %d\n", age); /*we need a new line here because the fscanf only get the number and discard the newline character in the file */
    printf("Grade: %f\n", grade);

    return 0;
}