// execDemo.c

#include<stdio.h>
#include<stdlib.h>
/*
 unistd.h is a C and C++ header file that provides
 access to the POSIX operating system API.
 It defines functions for crypt, signals,
 filesystem, process, user/group, and more.
*/
#include<unistd.h>

/*
execvp : Using this command, the created child process
does not have to run the same program as the parent process does. 
The exec type system calls allow a process to run any program files, 
which include a binary executable or a shell script. 
*/

int main() {
    // a NULL terminated array of character pointers
    char *args[]={"./EXEC", NULL};

    // int execvp (const char *file, char *const argv[]);
    execvp(args[0], args);

    /* all statements are ignored after execvp() call
    as this whole process(execDemo.c) is replaced by another process (EXEC.c)
    */
    printf("Ending......");
    // wk3$ gcc execDemo.c -o execDemo
    // wk3$ ./execDemo
    return 0;
}