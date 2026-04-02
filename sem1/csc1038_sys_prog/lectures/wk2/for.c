#include <stdio.h>

int main()
{
    int i;
    for(i = 0; i <= 10; ++i)
    {
        printf("The value of i is: ");
        printf("  %d\n", i);
    }

    // there is a problem with the next line as
    // i is declared inside the for loop.
    // need to put i outside
    printf("%d\n", i);

    i = 1;
    for(i = 0; i < 3; ++i)
{
    printf("*****\n");
}
    return(0);
}