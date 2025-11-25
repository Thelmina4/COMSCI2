#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// stdio.h for writing to and reading from external devices.
// The C library provides functions for reading and writing to or from
// data streams.

int main(int argc, char*argv[])
{
    FILE *pfile = NULL;
    char *filename = "myname.txt";
    pfile = fopen(filename, "w");
    if(!pfile)  // Open myfile.txt to write it
        printf("Failed to open %s.\n", filename);

    fprintf(pfile,"%s", argv[1]);
    fclose(pfile);
	return 0;
}