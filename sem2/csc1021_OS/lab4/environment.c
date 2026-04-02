// environment.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // for getcwd() && chdir

extern char **environ;  // NULL terminated array of char *

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf("%s\n",environ[i]);
    exit(0);
    char *pwd = "PWD";
    // printf("\nGet the environment for %s : \n%s\n\n", pwd, getenv(pwd));
    // printf("\nWhich part of the ENV is this: : \n ==> \t %s\n\n", environ[4]);

    // changing the directory
    char s[100];
    printf("%s\n", getcwd(s, 100));

    // using the command
    chdir("..");

    // printing current working directory
    printf("%s\n", getcwd(s, 100));
    return 0;
}