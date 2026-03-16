#include <stdio.h>   // For input/output functions
#include <stdlib.h>  // For standard library functions (optional here)
#include <string.h>  // For string handling (not actually used here)

// Function prototype (optional, since it's not used in main)
int count_letter(const char *line, char letter);

// Main function starts here
int main(int argc, char* argv[]) {
    // Check if exactly 3 arguments are passed (program name + 2 inputs)
    if (argc != 3) {
        printf("Usage: %s <character> <string>\n", argv[0]);
        return 1; // Exit with error code
    }

    // Get the string from command line (second argument)
    char *str = argv[2]; // This is the string to search in

    // Get the character to search for (first argument)
    char *target = argv[1];

    // Check if the user provided a single character only
    if (strlen(target) != 1) {
        printf("Error: First argument must be a single character.\n");
        return 1; // Exit with error code
    }

    // Extract the actual character from the string
    char ch = *target;

    int count = 0; // Variable to store count of occurrences

    // Loop through each character in the string using a pointer
    while (*str != '\0') { // '\0' marks end of C string
        if (*str == ch) {  // Compare current character with target
            count++;       // Increment count if match found
        }
        str++; // Move pointer to next character
    }

    // Print the result
    printf("%d\n", count);

    return 0; // Exit successfully
}