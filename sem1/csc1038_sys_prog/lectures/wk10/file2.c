/* import libraries */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
	int width = atoi(argv[1]); // Read width from command line
	int length = atoi(argv[2]); //Read length from command line

    FILE *pfile = NULL; //Declare a new file pointer
    char *filename = "myRec.text"; //That is gonna be the file to store the result
    pfile = fopen(filename, "w");
    if(!pfile)  // Open myfile.txt to write it
        printf("Failed to open %s.\n", filename);

	/* draw the rectangle */
    for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
            /*remember that fputc expects a character, not a string, so we need to use single quote here for a character. */
			fputc('*', pfile);
		}
		fputc('\n', pfile);
	}
    fclose(pfile); //Close file
    pfile = NULL; //Reset the file pointer

    return 0;
}