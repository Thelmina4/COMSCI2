// sig.c

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h> // for exit()

void sighandler(int signum) {
    printf("Recieved a signal %d\n", signum);
}

void sig_term(int sig) {
    printf("\nProcess %d recieved SIGTEM (%d)\n", getpid(), sig);
    // !!! IMPORTANT EXIT(0) !!!
    exit(0);
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGTERM, sig_term);
    while(1) pause();
    return 0;
}

// gcc sig.c -o sig
// ./sig
// go to another terminal and type: ps -a
// my pid = 1462
// in the same terminal that I ran ps -a ...
// kill -SIGINT 1462
// kill -SIGTERM 1462 (because ctrl C won't work)