/*
SimpleShell - Assignment
stage: 1
version: 1.0
date:    February 2026
author:  Thelma Clarke
SID: 19746069
I have read and understood the DCU Academic Integrity and Plagiarism Policy.
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.

*/
/*********************************************************************
 This assignment is based off the lab assignments using the following as a basis
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
#include "simpleshell.h"

int main(int argc, char *argv[])
{

    // get the Shell ENV
    char shell_path[MAX_BUFFER];

    // argv[0] is the name of the program
    // realpath()
    // https://www.man7.org/linux/man-pages/man3/realpath.3.html
    if (realpath(argv[0], shell_path)) {
        setenv("SHELL", shell_path, 1);
    } else {
        perror("realpath failed");
    }

    /* get command line from input */
    char buf[MAX_BUFFER]; // line buffer
    char *args[MAX_ARGS]; // pointers to args strings
    char **arg;           // working pointer thru args

    // turn stdin to FILE *input
    FILE *input;
    // No arguments → interactive mode
    if (argc == 1) {
        input = stdin;
    }
    // One argument → batch mode
    else if (argc == 2) {
        input = fopen(argv[1], "r");
        if (!input) {
            perror("Error opening batch file");
            exit(1);
        } 
    } else {
        fprintf(stderr, "Usage: %s [batchfile]\n", argv[0]);
        exit(1);
    }

    /* Keep reading input until quit or eof of redirected input */
    while (1) {
        // only print a promp if getting from stdin
        if (input == stdin) {
            char cwd[512];
            char prompt_buffer[1024];
            char *prompt = "==> ";

            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                char *last_dir = strrchr(cwd, '/');
                last_dir = make_prompt(last_dir, cwd);

                snprintf(prompt_buffer, sizeof(prompt_buffer),
                         "%s%s", last_dir, prompt);

                fputs(prompt_buffer, stdout);
                fflush(stdout); // VERY IMPORTANT
            }
        }

        /* ---------- READ BATCH FILE ---------- */
        if (fgets(buf, MAX_BUFFER, input) == NULL) {
            break; // EOF
        }
        /* REMOVE \n AND \r  in input file */
        buf[strcspn(buf, "\r\n")] = '\0';

        /* ---------- TOKENISE ARGS ---------- */
        arg = args;
        *arg++ = strtok(buf, SEPARATORS);

        while ((*arg++ = strtok(NULL, SEPARATORS)))
            ;

        if (!args[0])
            continue;

        /* ---------- INTERNAL COMMANDS ---------- */

        if (!strcmp(args[0], "clear") || !strcmp(args[0], "clr")) {
            // "clear" command
            system("clear");
            continue;
        }
        // long list all the files in curr dir
        if (!strcmp(args[0], "dir")) {
            // "ls -al" command
            
            handle_dir(args);
            
            continue;
        }
        // quit the program
        if (!strcmp(args[0], "quit") || !strcmp(args[0], "q"))
            break;

        // list all the environment variables, changing SHELL="bin/bash" to the below
        if (!strcmp(args[0], "environ") || !strcmp(args[0], "env")) {
            handle_env();
            continue;
        }

        // echo command
        if (!strcmp(args[0], "echo")) {
            handle_echo(args);
            continue; // Go back to the prompt
        }

        if (strcmp(args[0], "cd") == 0) {
            handle_cd(args);
            continue;
        }

        if (strcmp(args[0], "pause") == 0) {
            //  Ctrl+Z — Sends SIGTSTP (Signal Terminal Stop)q
            handle_pause();
            continue;
        }

        if (!strcmp(args[0], "help")) {
            system("more ./manual/readme.txt");
            continue;
        }
        printf("Command not recognised: %s\n", args[0]);
    }
    if (input != stdin) {
        fclose(input);
    }
    return 0;
}

// implemented functions in utility.c
