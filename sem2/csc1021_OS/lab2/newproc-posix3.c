/**
 * This program forks a separate process 
 * using the fork()/exec() system calls.
 *
 * Figure 3.08
 
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	int status;
	pid_t cpid;

	/* fork a child process */
	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0) { /* child process */
		printf("I am the child %d\n",pid);
		while(1);
        // return 0;
	}
	else { /* parent process */
		printf("I am the parent %d\n",pid);
		while(1);
        // The wait() system call can be passed a
        // parameter that allows the parent to
        // obtain the exist status of a child
        // process.
        // cpid = wait(&status);
		// printf("Child Complete (pid=%d) with status=%d\n", cpid, status);
	}
    
    return 0;
}

// gcc newproc-posix3.c -o newproc-posix3
// ./newproc-posix3
// strace ./newproc-posix3