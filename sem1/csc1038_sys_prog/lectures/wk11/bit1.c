#include<stdio.h>

int main() {
    int a = 5; //101
    int b = 2; //010
    int x = 5;
    int y = 7;
    // printf("%d + %d = %d | %d = %d\n", a, b, a, b, a | b);
    printf("Before: x = %d, y = %d\n", x, y);

    int tmp = x;
    x = y;
    y = tmp;
    // On the other hand, this algorithm does the same:

    // x ^= y;
    // y = x ^ y;
    // x ^= y;

    printf("After: x = %d, y = %d\n", x, y);

    // printf("a + b = %d\n", a + b); //There is NO carry involved here
    // printf("a|b = %d\n", a|b);


    // a = 5;
    // b = 7;

    // printf("a + b = %d\n", a + b);
    // printf("a|b + a&b = %d\n", (a|b) + (a&b)); //There is carry involved here
}

// the output is 96