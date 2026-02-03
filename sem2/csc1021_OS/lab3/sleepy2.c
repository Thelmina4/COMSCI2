// sleepy2.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigterm(int sig) {
    printf("\nProcess %d received SIGTERM (%d)\n", getpid(), sig);
    printf("Cleaning up and exiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sleep_seconds>\n", argv[0]);
        exit(1);
    }

    int t = atoi(argv[1]);
    unsigned int slept;

    // Register signal handler
    signal(SIGTERM, handle_sigterm);

    printf("Process started with PID %d\n", getpid());

    while (1) {
        slept = sleep(t);
        printf("process=%d ---- slept=%u\n", getpid(), slept);
    }
}

// in a different terminal run ...
// kill -SIGTERM <pid>