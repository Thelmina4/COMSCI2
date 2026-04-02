// headerfile, it tells both .c files about the shared functions and global variables.

#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>          // realpath()
#include<unistd.h>          // for getcwd() && chdir && exec() && pid_t
#include<errno.h>           // syserr
#include<sys/types.h>       // pid_t
#include<sys/wait.h>        // waitpid
#include<signal.h>          // signal checking for zombies 

#define MAX_BUFFER 1024     // MAX line buffer
#define MAX_ARGS 64         // max # of args
#define SEPARATORS " \t\n"  // token separators

// external variables
extern char **environ;      // NULL terminated array of char *
extern int errno;           // system error number 

// Prototypes for functions defined in utility.c
// error handling
void syserr(char *msg);

// parse the prompt line to pwd
void handle_echo(char **args);

// handle the input of cd into command line.
void handle_cd(char **args);

// handle the input of environ or env
void handle_env();

// pause command
void handle_pause();

// get cwd, shorten it to everything after / else its cwd
char *make_prompt(char * last_dir, char *cwd);

void handle_dir(char **args);

// forking of pid so that we can handle commands outside the listed ones
void handle_fork(char **args, char *shell_path, char *infile, char *outfile, int append, int background);

// redirections needs to return the saved dup
FILE *redirect_output(char *outfile, int append);

// restore after redirection
void restore_output(FILE *saved_stdout);

// Marcel the shell
void marcel();

#endif

// author:  Thelma Clarke
// SID: 19746069
// I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
// I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
