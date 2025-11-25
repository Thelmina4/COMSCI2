/*
program lab2-draw-empty-square.c
taking an argument as width and draw a square of "*".
Remember to add a newline character \n at the end.

Author: thelma clarke 19746069
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);

    // Outer rows
    // for (int i = 0; i < size; ++i) {
    for (int i = 0; i < size; i++) {
        // Inner cols
        for (int j = 0; j < size; j++) {
            // Check if it's boundary 
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // next line 
    }
    return 0;
}