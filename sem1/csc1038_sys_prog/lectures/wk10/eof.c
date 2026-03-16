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

    /* use EOF to read data from the file while we don't know the length */
    int count = 0;
	while(EOF != fscanf(pfile, "%d", &a[count])){ //As long as the pointer is not reaching end-of-file
        count++;
    }

    fclose(pfile);
    pfile = NULL;

    /* Calculate sum */
    sum = sumIntegers(a, count);

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