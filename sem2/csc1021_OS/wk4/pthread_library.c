// pthread_library.c

// p in pthread is: posix thread
#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum;    /* this data is shared by the thread */

void *runner(void *param); /* the thread */

int main(int argc, char *argv[]) {
    pthread_t tid; /* the thread Identifier */
    pthread_attr_t attr; /* set of attributes for the thread */

    if (argc != 2) {
        //  argument is of type ‘FILE *
        fprintf(stderr, "Usage: a.out <int value>\n");
        // exit(1);
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        // note the use of "fprintf" this is because we are passing a FILE
        //  argument is of type ‘FILE *
        fprintf(stderr, "Argument %d negative\n", atoi(argv[1]));
        // exit(1);
        return -1;
    }

    // get the default attributes
    pthread_attr_init(&attr);

    // create the thread
    pthread_create(&tid, &attr, runner, argv[1]);

    // now wait for the thread to exit
    // “don’t continue until this thread exits”
    pthread_join(tid, NULL);

    printf("Sum = %d\n", sum);
}

// imlplemented runner function
// the thread will begin control in the is fucntion
void *runner(void *param) {
    int i, upper = atoi(param);
    sum = 0;
    if (upper > 0) {
        for (i = 1; i<= upper; i++) {
            sum += i;
        }
    }
    pthread_exit(0);
}