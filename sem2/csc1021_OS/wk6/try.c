#include<stdio.h>
#include<signal.h>
#include <unistd.h>

void sighandler(int signum){
    printf("recieved signal %d\n", signum);
}  

int main() {
    int x = 1;
    // if (fork() == 0) {
    //     x = 2;
    // }
    // printf("%d\n", x);

    // signal(SIGINT, sighandler); 
    // while(1);
    int val = 10; // Global variable

    if (fork() == 0) {
        // Inside the CHILD process
        val = 20; 
        while(1) printf("Child val: %d\n", val); 
    } else {
        // Inside the PARENT process
        // wait(NULL); // Wait for child to finish
        printf("Parent val: %d\n", val);
    }
    return 0;
}