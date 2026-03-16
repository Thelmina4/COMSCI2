/* import libraries */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int sumIntegers(int a[], int length)
{
    int sum = 0;
    for(int i = 0; i < length; ++i)
    {
        sum += a[i];
    }
    return sum;
}

int main(int argc, char*argv[])
{
    FILE *pfile = NULL;
    char *filename = "inputIntegers.txt";
    pfile = fopen(filename, "r");
    if(!pfile)  // Open myfile.txt to write it
        printf("Failed to open %s.\n", filename);

    int a[MAX] = {0};
    int length = 0;
    int sum = 0;

	fscanf(pfile, "%d", &length);
    for(int i = 0; i < length; i++)
    {
        fscanf(pfile, "%d", &a[i]);
    }
    fclose(pfile);
    pfile = NULL;

    /* Calculate sum */
    sum = sumIntegers(a, length);

    /*Store result to a file */
    filename = "outputIntegers.txt";
    pfile = fopen(filename, "w");
    if(!pfile)  // Open myfile.txt to write it
        printf("Failed to open %s.\n", filename);

    fprintf(pfile, "%d", sum);
    fclose(pfile);
    pfile = NULL;

    return 0;
}