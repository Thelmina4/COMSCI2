#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle_sigterm(int sig) {
    printf("\nProcess %d received SIGTERM (%d)\n", getpid(), sig);
    printf("Cleaning up and exiting...\n");
    exit(0);
}

void sig_int(int sig) {
    printf("process %d revieve SIGINT (%d)\n", getpid(), sig);
}

int main(int argc, char *argv[]) {
    // Register signal handler
    signal(SIGTERM, handle_sigterm);
    signal(SIGINT, sig_int);
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sleep_seconds>\n", argv[0]);
        exit(1);
    }

    printf("this is process %d\n", getpid());

    int t = atoi(argv[1]);
    unsigned int slept;
    printf("Process started with PID %d\n", getpid());

    int upper;
    scanf("%d", &upper);

    printf("This is the sleep while loop\n");
    int i = 0;
    while (i < upper) {
        slept = sleep(t);
        printf("process: %d\t slept: %d\t i: %d\n", getpid(), slept, i);        
        i++;
    }
}

// in a different terminal run ...
// kill -SIGTERM <pid>
// kil -SIGINT <pid>