#include <stdio.h>
#include <stdlib.h>

void binToDec(int bits[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result = result * 2 + bits[i];
    }

    printf("Decimal value: %d\n", result);
}

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 9) {
        printf("Error: Enter between 1 and 8 binary digits.\n");
        return 1;
    }

    int n = argc - 1;
    int bits[8];

    for (int i = 0; i < n; i++) {
        if (argv[i+1][0] != '0' && argv[i+1][0] != '1') {
            printf("Error: Input must be only 0 or 1.\n");
            return 1;
        }
        bits[i] = argv[i+1][0] - '0';   // convert char to int
    }

    binToDec(bits, n);

    return 0;
}
