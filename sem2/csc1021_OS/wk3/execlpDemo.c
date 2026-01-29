// execlpDemo.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        // execv needs a path passed to it
        // in the previous example, execvp, that needs a file passed to it
        // int execv(const char *path, char *const argv[]);
        execlp("/bin/ls", "ls", NULL);
    
        /*All statements are ignored after execvp() call as this whole 
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
        printf("Ending-----");
    
    return 0;
}