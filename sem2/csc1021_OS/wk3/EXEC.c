// EXEC.c 
// https://www.geeksforgeeks.org/c/exec-family-of-functions-in-c/
#include<stdio.h>
#include<unistd.h>
// don't rn this program
// go to execDemo.c and run that one
// this is showing the use of execvp()

int main()
{
    int i;
    
    // printf("I am EXEC.c called by execvp() ");
    printf("I am EXEC.c called by execv() ");
    printf("\n");
    
    return 0;
}