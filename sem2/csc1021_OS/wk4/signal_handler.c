#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sighandler(int signum) {
   printf("Received a signal: %d\n", signum);
}

int main() {
   signal(SIGINT, sighandler);

   while(1);
   return 0;
}
// gcc signal_handler.c -o signal_handler
// ./signal_handler

// in another terminal "ps a" to find PID
// kill -SIGINT pid

// back to the terminal that the process was running in and see the output. 
// kill -SIGTERM pid
// to terminate the process
