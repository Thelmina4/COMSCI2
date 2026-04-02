// shell_f.c

/*
  forkexec - skeleton program displaying fork and exec use

  usage:

    forkexec

    displays process id of parent and child before and after fork.
    executes the program 'sleepy' in the current directory with a single
    command line argument of 10. ('sleepy' is the program written during
    the first exercise. This call should cause sleepy to print out 10
    seconds of output before terminating)


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

//  This program exists to show two core Unix ideas:

// fork() creates a new process
// exec() replaces a process image
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern int errno;    // system error number
void syserr(char *); // error report and abort routine

int main(int argc, char *argv[])
{
    pid_t pid; // process ID
    int rc;    // return code

    pid = getpid(); // get our own pid
    // Only one process exists at this point.
    printf("Process ID before fork: %d\n", (int)pid);

    // After this line: switch (fork())
    // Two processes exist
    // Both continue execution from here
    switch (fork())
    {
    case -1: // case that the fork failed (rare)
        syserr("fork");
    case 0:             // execution in child process
        // This PID will be different from the parent.
        pid = getpid(); // get child pid
        printf("Process ID in child after fork: %d\n", pid);
        
        // This is the entire point of the example.
        // execlp("sleepyforkexec", "sleepyforkexec", "10", NULL);
        // Child stops being shell_f
        // Child becomes sleepyforkexec
        // PID stays the same
        // Code, data, stack are replaced

        // If exec succeeds:
        // nothing after it runs
        execlp("./sleepyforkexec", "sleepyforkexec", "10", NULL);
        syserr("execl"); // error if return from exec
    }

    // continued execution in parent process

    pid = getpid(); // reget our pid
    printf("\nProcess ID in parent after fork: %d\n", pid);

    exit(0);
}

void syserr(char *msg) // report error code and abort
{
    fprintf(stderr, "%s: %s", strerror(errno), msg);
    //    abort(errno);
}
