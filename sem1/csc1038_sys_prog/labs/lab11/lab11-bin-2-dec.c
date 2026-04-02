/*
Author: Thelma Clarke
SID: 19746069

file: lab11-bin-2-dec.c

input: 
accepts up to 8 digits as command line arguments.
The digits can only be the numbers one (1) or zero (0)
NO other input is deemed valid

known:
Note that you may assume that the first digit entered is the most significant bit,
the second is the next most significant etc.
 calculation should be performed in a void function
output:

convert this string of binary digits to its decimal equivalent

Plan:
Make an arr 0 x 8
take in array from command line
start at the back and work my way forward
if a number is != 0 || != 1 then Only digits 1 and 0 are permitted.

binary - > dec = digit^n-i-1
i = 0, n =6, -1 = 5
i=1, n=6 - 1-1 = 4

*/

// libraries
#include <stdio.h>
#include <stdlib.h>

// prototype functions

// convert to binary
void binToDec(int bits[], int n);

// Validate the length of argc


int main(int argc, char *argv[]) {

    if (argc > 9) {
        printf("Too many binary digits entered.\n");
        return 0;
    }
    // find the len of args
    int n = argc - 1;
    int bits[n];

    for (int i = 0; i < n; i++) {
        if (argv[i+1][0] != '0' && argv[i+1][0] != '1') {
            printf("Only digits 1 and 0 are permitted.\n");
            return 0;
        }
        bits[i] = atoi(argv[i+1]);
    }

    binToDec(bits, n);

    return 0;
}


// implement the functions
void binToDec(int bits[], int n) 
{
    int result = 0;

    for (int i = 0; i < n; i++) {
        // printf("result: %d,  result * 2 + bits[i] : %d, bits[i]: %d\n", result,  result * 2 + bits[i], bits[i]);
        result = result * 2 + bits[i];
    }

    printf("%d\n", result);
}