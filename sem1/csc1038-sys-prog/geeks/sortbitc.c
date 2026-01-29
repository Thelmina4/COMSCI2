#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Function to count set bits (1s) in an integer
// This function uses bitwise operators for better performance
int countSetBits(int a) {
    int count = 0;
    // Brian Kernighan's Algorithm
    while (a > 0) {
        a &= (a - 1);
        count++;
    }
    return count;
}

// Function to simultaneously sort two arrays (arr and bitCnt)
// based on the values in bitCnt, using Insertion Sort in descending order
// of bit count. arr will be updated accordingly.
void insertionSort(int arr[], int bitCnt[], int n) {
    for (int i = 1; i < n; i++) {
        int key1 = bitCnt[i]; // Bit count of element arr[i]
        int key2 = arr[i];    // Value of element arr[i]
        int j = i - 1;

        // Compare using bitCnt in descending order (bitCnt[j] < key1)
        while (j >= 0 && bitCnt[j] < key1) {
            // Shift elements in both arrays
            bitCnt[j + 1] = bitCnt[j];
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key elements in their correct positions
        bitCnt[j + 1] = key1;
        arr[j + 1] = key2;
    }
}

// Function to sort an array according to the count of set bits (1s)
void sortBySetBitCount(int arr[], int n) {
    // 1. Create a dynamic array to store the count of set bits.
    // In C, dynamic allocation is required to handle array creation inside a function.
    int* bitCnt = (int*)malloc(n * sizeof(int));
    if (bitCnt == NULL) {
        // Handle allocation failure
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    // 2. Calculate and store the set bit count for each element.
    for (int i = 0; i < n; i++) {
        bitCnt[i] = countSetBits(arr[i]);
    }
    
    // 3. Sort both arrays simultaneously using insertion sort.
    insertionSort(arr, bitCnt, n);

    // 4. Free the dynamically allocated memory.
    free(bitCnt);
}

int main() {
    // The C equivalent of std::vector<int> is a C array.
    // The size of the array must be passed explicitly to functions in C.
    int arr[] = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortBySetBitCount(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Add a newline for clean output

    return 0;
}