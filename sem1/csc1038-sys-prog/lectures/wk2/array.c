#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int storage[100] = {0}; // it's fine to put in less values than 100, e are jsut assigning a size
    int length = atoi(argv[1]);
    for (int i = 0; i < length; i++){
        storage[i] = atoi(argv[i+2]); // putting in from argv[2] for the first input, which is i = 0+2
    }
    for(int i = 0; i < length; i++){
        printf("Elemnet Storage[$d] is  %d\n", i, storage[i]);
    }
    return (0);
}