/*
* this program forks a separate process
* using the fork() / exec() system calls.
*
* figure 3.08
* 
* @author Silberschatz, Galvin, & Gagne
* Operating System Concepts - Tenth Edition
* Copyright John Wiley & Sons - 2018
*
*/

// newproc-posix.c

#include <stdio.h>
// exec family of functions is defined in the unistd.h
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    // The pid_t data type is a signed integer type which is
    // capable of representing a process ID. 
    /* data types that ends with "_t", are usually
    a defined type variable in C and C++ as an unwritten law. 
    according to that law, "pid_t" is a data type which is defined
    somewhere else but "int" a standard type; 
    */
    pid_t pid;

    /* fork a child process */
    pid = fork();

    /* the below is an example of defensive programming.
    When dealing with system level calls,
    it’s wise to include error checks whenever possible.
    */
    if (pid < 0) { /* error occured */
        fprintf(stderr, "Fork failed to occur\n");
        return 1;
    }
    else if (pid == 0) { /* child process */
        printf("I am the child %d\n", pid);

        // execlp("/bin/ls", "ls -l", NULL);
        // execlp("sh", "sh", "-c", "ls -l | grep '\\.c$'", NULL);
        // sh -c runs the string as a shell command

        // the next line is the most advanced version
        // execlp("sh", "sh", "-c", "find . -name '*.c' -exec ls -l {} +", NULL);

        // execlp() does not understand pipes or wildcards
        // | and * are handled by the shell
        // To use them:
        //      either run sh -c "command"
        //      or manually pipe + fork + dup2 + exec
        printf("Does this line get printed?\n");
    }
    else { /* parent process */
        /* parent will WAIT for the child to complete */
        printf("I am the parent %d\n", pid);
        // w/o the wait() system call, the child ps won't exit to the parent ps
        wait(NULL);
        printf("Child complete %d\n", pid);
    }
    /* See ‘man execlp’:
    “The exec() family of functions replaces the current process image with a new
    process image.”
    So, after fork(), in the child process, the process image (i.e., the code, data,
    etc) are replaced, meaning the code to print this line has been replaced.
    */
    return 0;
}
