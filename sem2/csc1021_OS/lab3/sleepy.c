#include<stdio.h>

// unistd.h provides access to the POSIX operating system API
// includes Unix and Unix-like operating systems,
//  such as GNU variants, distributions of Linux and BSD,
//  and macOS, and compilers such as GCC and LLVM.

// It is typically made up largely of system call wrapper functions
//  such as fork, pipe and I/O primitives (read, write, close, etc.).
#include<unistd.h> // getpid() && sleep
#include<stdlib.h>

int main(int argc, char * argv[]) {
    // take in the time we want the program to sleep from command line
    int t = atoi(argv[1]);

    unsigned int slept;

    while(1) {
        // man7.org/linux/man-pages/man3/sleep.3.html
        slept = sleep(t);
        printf("process=%d ---- slept=%d\n", getpid(), slept);
    }
}
// gcc -o sleepy sleepy.c
// ./sleepy.c 5