/*
Author: Thelma Clarke
SID: 19746069
Date: 8/12/2024

preface:
& - AND - returns 1 if both are 1, 0 if they are different
| - OR - returns 1 if either or both are 1
^ - XOR - exclusive or, produces a 1 if both bits are different and 0 if they’re the same
file: and_bitwise.c
 1. Write a C function that takes an integer 
        and determines if it is even or odd using & only.

 2. Swap two numbers using XOR (no temp variable)
    Problem: Write a function that swaps two integers using only XOR.

 3. takes a single integer (n) 
    and returns how many bits in its binary representation are 1.

 4. Check if a number is a power of 2
    Problem: Write a function that returns 1 if a number is a power of 2, 
    otherwise 0.

 5. Get the i-th bit of a number
    Problem: Write a function int getBit(int n, int i) 
    that returns 0 or 1 for bit position i.

 6. Set the i-th bit of a number
    Problem: Write a function that sets index i in n to 1 and
    returns the new number.

 7. Clear the i-th bit of a number
    Problem: Write n with bit i cleared.

 8. Toggle (flip) the i-th bit
    Problem: Flip the bit at position i.
    Hint: n ^ (1 << i)

 9. Extract the lowest set bit
    Problem: Write a function that returns the
    lowest (rightmost) set bit in n.
    Example:
    n = 12 (1100b) → result = 4 (0100b)
    Hint:
    n & -n

 10. Bitmask problem — store permissions in a single integer
    Problem: You have a permissions system using bit flags:

    Permission	Bit
    READ	0
    WRITE	1
    EXECUTE	2

    Write functions:

    addPermission(int *perm, int flag)

    hasPermission(int perm, int flag)

    removePermission(int *perm, int flag)

    Hint:

    Add → *perm |= (1 << flag)

    Check → perm & (1 << flag)

    Remove → *perm &= ~(1 << flag) 

Plan:


*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// prototype functions
// 1. return odd/even
bool andBit(int x);

// printBit whether odd or even
void printBit(bool andBit);

// 2. swap using XOR
void swapXor(int x, int y);

// 3. count how many 1s there are in the bits
// eg. 5 has 2, 0101
int countBits(int n);

// 4. returns 1 if a number is a power of 2, otherwise 0.
int powerTwo(int x);

// 5. Get the i-th bit of a number
int getBit(int n, int i);
// 6. set i-th bit to 1, it's like adding 2^i to n if the bit is not already a 2
int setBit(int n, int i);

// 7. Clear the i-th bit of a number
int clearBit(int n, int i);

// 8. Toggle (flip) the i-th bit
int toggle(int n, int i);

// 9. Extract the lowest set bit
int lowestSetOne(int n);

// 10. Bitmask problem — store permissions in a single integer
// Add a permission (set a bit to 1)
void addPermission(int *perm, int flag);

// Check if a permission exists (is the bit = 1?)
int hasPermission(int perm, int flag);

// Remove a permission (clear a bit to 0)
void removePermission(int *perm, int flag);

// 11. 2's complement
int twosComplement(int n);

// 12. Decimal to binary
void printBinary(int n);

void printBinaryTrimmed(int n);

// return the binary as a string
void toBinary(int n, char *out);

// Print binary padded to nearest byte boundary (8,16,24,... bits)
void printBinaryPadded(int n);

// 13. dec to binary
void printHex(int n)
{
    int started = 0;

    // 32-bit integer → 8 hex digits
    for (int shift = 28; shift >= 0; shift -= 4) {
        int digit = (n >> shift) & 0xF;   // extract 4 bits

        if (digit != 0 || started || shift == 0) {
            started = 1;

            if (digit < 10)
                printf("%d", digit);
            else
                printf("%c", 'A' + (digit - 10));
        }
    }
    printf("\n");
}


// ######################################################
// main function
int main(int argc, char *argv[]) {

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("1&0 %d, 1&1: %d, 0&0: %d\n", 1&0, 1&1, 0&0);
    printf("1|0 %d, 1|1: %d, 0|0: %d\n", 1|0, 1|1, 0|0);
    printf("1^0 %d, 1^1: %d, 0^0: %d\n", 1^0, 1^1, 0^0);
    printf("1&-1 %d: 12&-12 %d, 4&-4: %d\t 3&-2: %d\n", 1&-1, 12&-12 , 4&-4, 3&-2);

    // 1. 
    printBit(andBit(x));
    // 2.
    swapXor(x, y);
    // 3.
    // printf("countBits: %d\n", countBits(-1));
    printf("countBits: %d\n", countBits(x));
    // 4.
    int z = 128;
    int p = powerTwo(z);
    for (int i = 1; i< 10;i++) {
        printf("%d is a power if 1, not a power if 0: %d\n", i, powerTwo(i));
    }
    // 5. 
    for (int i = 0; i < 12;i++) {
        printf("getBit %d\n", getBit(i, 3)); 
    }

    // 6. setbit
    for (int i = 0; i < 10;i++) {
        printf("setBit %d to  %d\n", i, setBit(i, 1)); 
    }

    // 7. clearBit
    for (int i = 0; i < 11;i++) {
        printf("clearBit %d to  %d\n", i, clearBit(i, 1)); 
    }

    // 8. toggle ith bit to 2 in this case
    for (int i = 0; i < 11;i++) {
        printf("toggle %d to  %d\n", i, toggle(i, 1)); 
    }
    // 9. 
    for (int i = 0; i < 32;i++) {
        printf("the right most 1 of %d is:  %d\n", i, lowestSetOne(i)); 
    }

    // 10. permissions
    // Start with no permissions
    int perm = 0;

    // Add permissions
    addPermission(&perm, 0); // READ
    addPermission(&perm, 2); // EXECUTE

    printf("Permissions value: %d\n", perm);

    // Check permissions
    printf("Has READ?    %d\n", hasPermission(perm, 0)); // 1
    printf("Has WRITE?   %d\n", hasPermission(perm, 1)); // 0
    printf("Has EXECUTE? %d\n", hasPermission(perm, 2)); // 1

    // Remove EXECUTE
    removePermission(&perm, 2);

    printf("After removing EXECUTE, has EXECUTE? %d\n",
        hasPermission(perm, 2)); // 0
     
    // 11. 2's complement
    for (int i = 0; i < 32;i++) {
        printf("2's complement of %d is:  %d\n", i, twosComplement(i)); 
    }

    // 12 decimal to binary
    printBinary(12);
    printBinaryTrimmed(y);

    char *out;
    toBinary(y, out);
    printf("out = %s\n", out);

    printBinaryPadded(y);

    // 13. 
    printHex(255);     // FF
    printHex(4095);    // FFF
    printHex(17);      // 11
    printHex(305419896);  // 12345678

    return 0;
}

// ######################################################

// implementation of Functions

// the next 2 are together
bool andBit(int x)
{
    if (x & 1) return false;
    return true;
}
void printBit(bool andBit)
{
    if (andBit) {
        printf("This is even\n");
    } else {
        printf("This is odd\n");
    }
}


void swapXor(int x, int y)
{
    x = x^y;
    // if x was -7 and y = 4
    //  x = x^y, x = -7+4 = -3
    printf("x: %d\n", x);
    y = x^y;
    printf("y: %d\n", y);

    // need the next line to complete the cycle
    x = x^y;
    printf("XOR: %d, %d\n", x, y);
}

int countBits(int n) {
    // this line works on negative numbers, as the number is now pos
    unsigned int x = (unsigned int)n;  // reinterpret bits as unsigned

    int count = 0;
    while (x > 0) {
        // printf("before x = %d\n", x);
        // the one less is always the opposite, either odd or even.
        x = x & (x - 1);  // clear lowest set bit
        // printf("%d: x, %d: (x - 1), %d: x & (x - 1); \n", x, (x - 1), x&(x - 1));
        count++;
    }

    // or using shift instead ...
    // but it always runs 32 iterrations
    // while (x > 0) {
    //     count += (x & 1);   // check lowest bit
    //     x >>= 1;            // shift right

    // }
    return count;
}

int powerTwo(int x)
{
    return countBits(x) == 1;
}

// 5. Get the i-th bit of a number
int getBit(int n, int i) 
{
    // n is shifted over to the i-th bit
    // return if 1 or 0, 1 & 1 == 1, else 0
    return (n >> i) & 1;
}

// 6. set i-th bit to 1
int setBit(int n, int i)
{
    // (1 << i) shifts the binary number 1 left by i positions.
    // adding 2**i to n
    n = n | (1<<i);
    return n;
}

int clearBit(int n, int i)
{
    // (1 << i) creates a mask with a 1 at bit i.
    // ~(1 << i) flips it: bit i becomes 0, all other bits become 1.
    // ANDing with this mask forces bit i to become 0.
    // eg 10 minus 2 = 8
    // 1010 & 1101 (not 2) = 1000
 
    return n & ~(1 << i);
}

// 8. Toggle (flip) the i-th bit
int toggle(int n, int i)
{
    // if n == 8, 1000
    // toggle bit 1 == 0010, (1 << i)
    // should return 10?
    // so either returning + or - 2
    return n = n ^ (1 << i);
}

int lowestSetOne(int n)
{
    // if n == 12, 1100, the rightmost bit is 0100 (4)
    // count 1 & shift << till x == 1.
    // return power count?
    // OR
    // if 12 == 1100, -12 == 0100 if I & them = 0100
    return n & -n;
}

// 10. Bitmask problem — store permissions in a single integer
// Add a permission (set a bit to 1)
void addPermission(int *perm, int flag) {
    // POINTERS
    // To change a variable inside a function, you must pass its address
    // Then the function can dereference the pointer and modify the original
    
    // OR sets the bit at position flag
    *perm |= (1 << flag);
}

// Check if a permission exists (is the bit = 1?)
int hasPermission(int perm, int flag) {
    // AND checks the bit at position flag
    return (perm & (1 << flag)) != 0;
}

// Remove a permission (clear a bit to 0)
void removePermission(int *perm, int flag) {
    // AND with NOT-mask clears the bit
    *perm &= ~(1 << flag);
}

// 11. 2's complement
int twosComplement(int n)
{
    // flips all bits, then adds 1.
    return (~n + 1);
}

// 12. Decimal to binary
void printBinary(int n)
{
    // assuming 32-bit int
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;   // extract i-th bit
        printf("%d", bit);
    }
    printf("\n");
}

void printBinaryTrimmed(int n)
{
    int started = 0;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;

        if (bit == 1)
            started = 1;

        if (started)
            printf("%d", bit);
    }

    if (!started)
        printf("0"); // n was 0
    printf("\n");
}

void toBinary(int n, char *out)
{
    int idx = 0;
    for (int i = 31; i >= 0; i--)
        out[idx++] = ((n >> i) & 1) + '0';

    out[idx] = '\0';
}

// Print binary padded to nearest byte boundary (8,16,24,... bits)
void printBinaryPadded(int n)
{
    int bits = 0;
    int temp = n;

    // Count how many bits are needed
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }

    // Edge case: n = 0
    if (bits == 0)
        bits = 1;

    // Round bits up to next multiple of 8
    int paddedBits = ((bits + 7) / 8) * 8;

    // Print the padded binary
    for (int i = paddedBits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }

    printf("\n");
}