#include<stdio.h>

int main()
{
    // loop 1
    // for(int i = 0; i <= 10; ++i)
    // {
    //     printf("%d\n", i);
    // }

    // loop 2

    int i = 1;
    for(;;) // creates an infinite loop
    // it's up to me to set parameters to stopthe loop
    {   
        if(i <= 10)
        {
            printf("  %d", i++);
            continue;
        }
        else
        {
            break;
        }
    }
    /*The difference between ++i and i++
    comes down to when the increment happens.
    ++i (pre-increment) 
    increases the value of i first, then uses it. 
    i++ (post-increment) 
    uses the current value of i first, then increases it.*/
    return (0);
}