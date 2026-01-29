#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen() and strcpy()

// Function to print the array of strings
void printStringArray(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Function to merge two halves in a stable way
// arr is a pointer to an array of string pointers (char **)
void merge(char **arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Dynamically allocate temporary arrays for the two halves
    // L and R are arrays of char pointers (char *)
    char **L = (char **)malloc(n1 * sizeof(char *));
    char **R = (char **)malloc(n2 * sizeof(char *));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Memory allocation failed in merge!\n");
        exit(EXIT_FAILURE);
    }

    // Copy data (string pointers) to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the two halves in a stable way (by string length)
    // Note: strlen() is used to get the length of the string pointed to by L[i] or R[j]
    while (i < n1 && j < n2) {
        // Compare lengths for stable sort
        if (strlen(L[i]) <= strlen(R[j])) {
            arr[k++] = L[i++]; // Copy pointer
        } else {
            arr[k++] = R[j++]; // Copy pointer
        }
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free the dynamically allocated temporary arrays (only the arrays of pointers)
    free(L);
    free(R);
}

// Merge Sort (recursive)
void mergeSort(char **arr, int left, int right) {
    if (left < right) {
        // Calculate mid to prevent overflow: left + (right - left) / 2
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to sort strings based on their length
void sortByLength(char **arr, int n) {
    mergeSort(arr, 0, n - 1);
}

// Main function to handle command-line arguments
int main(int argc, char *argv[]) {
    // The number of strings to sort is argc - 1, as argv[0] is the program name
    int n = argc - 1;

    if (n <= 0) {
        printf("Usage: %s <string1> <string2> <string3> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // argv[1] through argv[argc-1] is the array of strings.
    // We can pass argv + 1 as the array starting point.
    // The type matches: char **argv is an array of char *, which is what the sort functions expect.
    char **arr = argv + 1;

    printf("Original array: ");
    printStringArray(arr, n);

    // Sort the array (the sorting functions modify the pointers within argv's structure)
    sortByLength(arr, n);

    printf("Sorted array (by length): ");
    printStringArray(arr, n);

    // Note: We do NOT need to free the array 'arr' here because it points into 'argv', 
    // which is memory managed by the operating system/C runtime.

    return 0;
}