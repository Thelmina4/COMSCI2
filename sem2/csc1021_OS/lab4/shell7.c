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
#include <errno.h>          // syserr

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

    // Extend parsing: detect redirection tokens
    char *infile = NULL;    // redirect >
    char *outfile = NULL;   // redirect <
    int append = 0;         // redirect >> append to the file

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

            // redirection of files & text
            // here we records filenames
            //  &&
            // truncates args so exec doesn’t see < or >
            for (int i = 0; i< args[i]; i++) {
                if (!strcmp(args[i], "<")) {
                    // the location of the file to take from is i+1
                    infile = args[i+1];
                    args[i] = NULL;
                } else if (!strcmp(args[i], ">")) {
                    // the location of the file to input to is i+1
                    outfile = args[i+1];
                    append = 0;
                    args[i] = NULL;
                } else if (!strcmp(args[i], ">>")) {
                    outfile = args[i+1];
                    // set append to 1
                    append = 1;
                    args[i] = NULL;
                }
            }
            pid_t pid = fork();

            if (pid == 0) {
                // 1. CHILD: Handle redirection (using infile/outfile)
                // 2. CHILD: Execute the command
                execvp(args[0], args);
                perror("execvp failed"); // Only runs if execvp fails
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                // PARENT: Wait for child to finish before showing the next prompt
                waitpid(pid, NULL, 0); 
            } else {
                perror("fork failed");
            }
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

                    printf("Restarting shell  ...\n");
                    execv(argv[0], argv);
                    perror("execv failed\n");
                    exit(1);
                }

                // the above are the internal commands,
                // now we move to the external commands using fork()

                pid_t pid = fork();
                switch(pid) {
                    case -1:
                        syserr("fork");  // rare case that the fork fails

                    case 0:
                        // 3 cases, there is an infile 
                        if (infile) {
                            // if infile is not NULL <
                            // note stdin here and stdout below for outfile
                            fropen(infile, "r", stdin);
                        }
                        if (outfile) {
                            if (append) {
                                freopen(outfile, "a", stdout);
                            } else {
                                freopen(outfile, "w", stdout);
                            }
                        }
                        // Still in the child:
                        execvp(args[0], args);
                        perror("exec failed\n");
                        exit(1);
                    }
                // in the parent
                wait(NULL);
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