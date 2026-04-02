/*
strtokeg - skeleton shell using strtok to parse command line
usage:
strtokeg
reads in a line of keyboard input at a time, parsing it into
tokens that are separated by white spaces (set by #define SEPARATORS).
can use redirected input if the first token is a recognised internal command,
then that command is executed. otherwise the tokens are printed on the display.
internal commands:
clear - clears the screen
quit - exits from the program
********************************************************************
version: 1.0
date:    December 2003
author:  Ian G Graham
School of Information Technology
Griffith University, Gold Coast
ian.graham@griffith.edu.au
copyright (c) Ian G Graham, 2003. All rights reserved.
This code can be used for teaching purposes, but no warranty,
explicit or implicit, is provided.
*******************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>        // for getcwd() && chdir
#define MAX_BUFFER 1024    // max line buffer
#define MAX_ARGS 64        // max # args
#define SEPARATORS " \t\n" // token separators

extern char **environ; // NULL terminated array of char *

int main(int argc, char **argv)
{
    char buf[MAX_BUFFER];  // line buffer
    char *args[MAX_ARGS];  // pointers to arg strings
    char **arg;            // working pointer thru args
    char *prompt = "==> "; // shell prompt
    /* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin))
    {
        /* get command line from input */
        fputs(prompt, stdout); // write prompt

        if (fgets(buf, MAX_BUFFER, stdin))
        { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf, SEPARATORS); // tokenise input

            while ((*arg++ = strtok(NULL, SEPARATORS)))
                ;

            // last entry will be NULL
            if (args[0])
            { // if there's anything there
                /* check for internal/external command */
                if (!strcmp(args[0], "clr") || !strcmp(args[0], "clear"))
                { // "clear" command
                    system("clear");
                    continue;
                }

                if (!strcmp(args[0], "quit") || !strcmp(args[0], "q")) // "quit" command
                    break;                                             // break out of 'while' loop

                if (!strcmp(args[0], "dir"))
                {
                    // "ls -al" command
                    system("ls -al");
                    continue; // break out of 'while' loop
                }

                // If command  is  NULL, then  a nonzero value if a shell is  available,
                // or  0  if  no shell is available.

                // If  a  child  process could not be created, or  its  status could not be retrieved,
                // the return  value  is  -1 and  errno  is set to indicate the error.

                // If a shell could  not be  executed  in  the child  process,  then the  return  value is
                // as though  the  child shell  terminated  by calling _exit(2) with the status 127.

                // If all  system  calls succeed, then the return   value  is  the termination status of
                // the child shell  used to  execute  command. (The termination status of a shell is the
                // termination status of the last  command  it executes.)
                if (!strcmp(args[0], "pwd"))
                {
                    char *p = "PWD";
                    printf("\nGet the environment for %s : \n%s\n\n", p, getenv(p));
                    system("pwd");
                    continue;
                }

                if (!strcmp(args[0], "environ") || !strcmp(args[0], "env"))
                {
                    int i;
                    for (i = 0; environ[i] != NULL; i++)
                        printf("%s\n", environ[i]);
                    continue;
                }

                if (!strcmp(args[0], "curdir"))
                {
                    if (args[1] == NULL)
                    {
                        char s[100];
                        printf("%s\n", getcwd(s, sizeof(s)));
                        continue;
                    }
                    // change from currdir
                    if (!strcmp(args[1], ".."))
                    {
                        chdir("..");
                    }
                }

                char *home = getenv("HOME");
                if (!strcmp(args[0], "gotodir"))
                {

                    // Case 1: "cd" with no argument → go to HOME
                    if (args[1] == NULL)
                    {
                        // char *home = getenv("HOME");
                        if (home == NULL)
                        {
                            fprintf(stderr, "cd: HOME not set\n");
                        }
                        else if (chdir(home) != 0)
                        {
                            perror("cd");
                        }
                        continue;
                    }

                    // Case 2: "cd <dir>"
                    if (chdir(args[1]) != 0)
                    {
                        perror("cd");
                    }
                    continue;
                }

                if (!strcmp(args[0], "restart")) {
                    // char *home = getenv("HOME");
                    // if (home == NULL)
                    // {
                    //     fprintf(stderr, "cd: HOME not set\n");
                    // }
                    // else if (chdir(home) != 0)
                    // {
                    //     perror("cd");
                    // }
                    printf("Restarting shell  ...\n");
                    execv(argv[0], argv);
                    perror("execv failed\n");
                    exit(1);
                }
                /* else pass command onto OS (or in this instance, print them out) */
                arg = args;
                while (*arg)
                {
                    fprintf(stdout, "%s ", *arg++);
                    fputs("\n", stdout);
                }
            }
        }
    }
    return 0;
}

// lab4$ gcc -o shell1 shell1.c
// lab4$ ./shell1
// ==> pwd

// Get the environment for PWD :
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4

// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4
// ==> curdir 
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4
// ==> pwd

// Get the environment for PWD :
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4

// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4
// ==> curdir ..
// curdir 
// ..
// ==> pwd

// Get the environment for PWD :
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4

// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS
// ==> gotodir
// ==> pwd

// Get the environment for PWD :
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4

// /home/thelmina4
// ==> gotodir /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4
// ==> pwd

// Get the environment for PWD :
// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4

// /mnt/c/Users/thelm/Documents/comsci/comsci2/COMSCI2/sem2/csc1021_OS/lab4
// ==>