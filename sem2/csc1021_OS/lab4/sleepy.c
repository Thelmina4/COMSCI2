#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sighandler(int sig) {
    printf("recieved the signal %d\n", sig);
}

void sig_term(int sig) {
    printf("Process %d reviecved SIGTERM (%d)\n", getpid(), sig);
    // !!!!! IMPORTANT TO EXIT !!!!
    exit(0);
}
// THE NEXT FUNCTIONs WILL NOT WORK

void sig_cont(int sig) {
    printf("Process ID , %d, recieved the signalID (%d) to cont\n", getpid(), sig);
    
}

void sig_stop(int sig) {
    printf("Process ID , %d, recieved the signalID (%d) to STOPPS\n", getpid(), sig);
    
}
void sig_quit(int sig) {
    printf("Process ID, %d, recieved the signal to QUIT w signalID %d\n", getpid(), sig);
    
}

int main(int argc, char * argv[]) {
    // take int he time that we want to sleep from command line
    if (argc <2) {
        return 0;
    }
    int t = atoi(argv[1]);

    // declare a variable for slept
    unsigned int slept;

    // the upper bound
    printf("How many times to you want the program to sleep? ");
    int upper;
    scanf("%d", &upper);

    printf("This is the sleep while loop\n");
    int i = 0;
    while (i < upper) {
        slept = sleep(t);
        printf("process: %d\t slept: %d\t i: %d\n", getpid(), slept, i);
        signal(SIGINT, sighandler);
        signal(SIGTERM, sighandler);
        // none of the bwlow work
        // signal(SIGSTOP, sig_stop);
        // signal(SIGQUIT, sig_quit);
        // signal(SIGCONT, sig_cont);
        
        i++;
    }
    printf("%d\n", getpid());
    return 0;
}
// gcc -o sleepy sleepy.c
// ./sleepy.c 5
// How many times to you want the program to sleep? 5
// This is the sleep while loop
// process: 864     slept: 0        i: 0
// process: 864     slept: 0        i: 1
// process: 864     slept: 0        i: 2