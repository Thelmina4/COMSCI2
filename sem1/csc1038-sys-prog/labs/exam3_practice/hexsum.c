#include <stdio.h>
#include <stdlib.h>

// ./hexsum 0x1A 0x2B

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hex1> <hex2>\n", argv[0]);
        return 1;
    }

    // Convert hex strings to integers
    int num1 = (int)strtol(argv[1], NULL, 16);
    int num2 = (int)strtol(argv[2], NULL, 16);
    // strtol : long int strtol (const char* str, char** endptr, int base);
    // Parses the C-string str interpreting its content as an integral number
    // of the specified base, which is returned as a long int value. 
    // If endptr is not a null pointer, the function also sets the value of endptr
    //  to point to the first character after the number.

    
    int sum = num1 + num2;

    printf("Decimal sum: %d\n", sum);

    return 0;
}
