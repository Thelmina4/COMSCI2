// pthreads_locks.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

int sum = 0;
pthread_mutex_t lock;

void *runner(void *param) {
    int upper = atoi(param);
    int local_sum = 0;

    for (int i = 1; i <= upper; i++)
        local_sum += i;

    pthread_mutex_lock(&lock);
    sum += local_sum;
    printf("Thread sum %d\nupper: %d\n", sum, upper);
    pthread_mutex_unlock(&lock);

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    if (argc != 2) {
        fprintf(stderr, "Usage: a.out <int value>\n");
        return -1;
    }

    // A mutex has two possible states: unlocked (not owned by any
    //    thread), and locked (owned by one thread).
    // https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
    pthread_mutex_init(&lock, NULL);
    pthread_attr_init(&attr);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&tid[i], &attr, runner, argv[1]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Sum = %d\n", sum);
}
