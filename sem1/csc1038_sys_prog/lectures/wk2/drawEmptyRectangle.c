#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    if (height < 1)
    {
        // the first line
        for (int i = 0; i < width; ++i)
        {
            printf("*");
        }
        printf("\n");

        int middle = width - 2;
        int lines = height - 2;
    
    }
        
    else 
    {
        for (int i = 0; i < width; ++i)
        {
            printf("*");
        }
    }

    return (0);

}
