// shared.c

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// global variable
int shared = 0;

void* writer(void* arg) {
    // after it sleep s for 1 sec, it changes that value of shared.
    sleep(1);       // give reader time to start
    shared = 42;
    printf("writer: set shared = %d\n", shared);
    return NULL;
}
void* reader(void * arg) {
    // the global shared == 0, so print that
    printf("REader: initial shared = %d\n", shared);

    // waiting for the value of shared to change
    while (shared == 0) {
        // busy wait
    }

    // once the writer has changed it can then print out the next line
    printf("Reader: saw \"shared\" change to : %d\n", shared);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // we pretend that both of these are started at the same time
    pthread_create(&t1, NULL, reader, NULL);
    pthread_create(&t2, NULL, writer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}