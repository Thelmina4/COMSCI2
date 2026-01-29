#include <stdio.h>
#include <stdlib.h> // For atoi, malloc, and free
#include <stdbool.h> // For using bool type

// --- Core Logic Function ---

/*
 * Finds the K-th smallest natural number remaining after removing elements in arr.
 * arr: The array of removed integers.
 * n: The size of the arr array.
 * k: The target count for the smallest element.
 * * Time Complexity: O(n * k) in the worst case.
 */
int findkthSmall(const int arr[], int n, int k) {
    // cnt tracks the count of remaining valid numbers found so far.
    int cnt = 0;
    // num iterates through the sequence of natural numbers (1, 2, 3, ...).
    int num = 1; 

    while (cnt < k) {
        bool isValid = true;
        
        // Check if the current natural number 'num' is in the removed list 'arr'.
        // O(n) check in the inner loop.
        for (int i = 0; i < n; i++) {
            if (arr[i] == num) {
                isValid = false;
                break; // Found, so stop checking and skip this number
            }
        }
        
        if (isValid) {
            cnt++; // This is a valid remaining number, increment the count.
        }
        
        // Move to the next natural number.
        num++;
        
        /* * Important Check: If 'num' exceeds a reasonable limit, it suggests 'k' 
         * is too large relative to the size and values in 'arr'.
         * We stop at a hardcoded limit (e.g., k + n + 10) to prevent infinite loops 
         * in cases where k is extremely large, though this approach relies on 
         * the assumption that the k-th element is found quickly.
         * For the Naive approach, the problem statement doesn't specify a bound.
         * For typical competitive programming scenarios, a bound is implied.
         */
        if (num > k + n + 1000) { 
            fprintf(stderr, "Warning: The required k-th element was not found within a reasonable bound.\n");
            return -1;
        }
    }
    
    // 'num' was incremented one last time after 'cnt' reached 'k'.
    // The k-th smallest element is the number before the last increment.
    return num - 1; 
}

// --- Command Line Processing Function ---

int main(int argc, char *argv[]) {
    // Input format: <program_name> k arr[0] arr[1] ... arr[n-1]
    
    // We need at least 2 arguments: the program name, k, and at least one array element.
    if (argc < 3) {
        printf("Usage: %s <k> <arr[0]> <arr[1]> ...\n", argv[0]);
        printf("Example: %s 4 1 3\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 1. Extract k (the first numerical argument)
    int k = atoi(argv[1]);
    
    // 2. Determine the array size (n)
    // n = total arguments - 2 (program name and k)
    int n = argc - 2;

    // 3. Allocate memory for the array of removed numbers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // 4. Populate the array from command-line arguments (starting from argv[2])
    for (int i = 0; i < n; i++) {
        // argv[i+2] corresponds to the array element arr[i]
        arr[i] = atoi(argv[i + 2]);
    }

    // 5. Find and print the result
    int result = findkthSmall(arr, n, k);
    printf("%d\n", result);

    // 6. Free the dynamically allocated array
    free(arr);

    return 0;
}