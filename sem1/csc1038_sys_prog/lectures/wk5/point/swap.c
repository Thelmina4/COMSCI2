#include<stdio.h>

// this one doesn't work, not sure why
// something to do with the address
void swapa(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
// this works
// int *a is making a pointer to the address of a
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;       //a is an address, so we put a * to get it's value
    *a = *b;
    *b = tmp;       // put tmp into the address of b
}

int main(int argc, char *argv[]) {
    int a = 5;
    int b = 7;

    int c[3] = {10, 30, 20};

    swapa(a, b);         // this doesn't work 
    swap(&a, &b);     // this is putting in the addresses
    swap(&c[1], &c[0]);  
    // the next line is the same as the above line
    // bu it brings up an error, neeed to figure out why
    // swap(a+1, a+2);  

    printf("%d, %d\n", a, b);

    printf("%d, %d\n", c[0], c[1]);

    return 0;
}