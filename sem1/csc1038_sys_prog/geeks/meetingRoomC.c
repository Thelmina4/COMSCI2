#include <stdio.h>
#include <stdlib.h> // For malloc, free, atoi, and qsort

// Define a structure for a meeting interval: {start_time, end_time}
typedef struct {
    int start;
    int end;
} Meeting;

// --- Helper Functions ---

/*
 * Comparison function for qsort to sort meetings by their start time.
 * This is the C equivalent of the default behavior of std::sort on a vector of vectors.
 */
int compareMeetings(const void *a, const void *b) {
    const Meeting *meetingA = (const Meeting *)a;
    const Meeting *meetingB = (const Meeting *)b;
    
    // Sort primarily by start time
    if (meetingA->start != meetingB->start) {
        return meetingA->start - meetingB->start;
    }
    // Secondary sort by end time (optional, but good practice)
    return meetingA->end - meetingB->end;
}

// --- Main Logic Function ---

/*
 * Checks if a person can attend all meetings without overlap.
 * arr: Pointer to the array of Meeting structs.
 * n: The number of meetings in the array.
 * Returns 1 (true) if all meetings can be attended, 0 (false) otherwise.
 */
int canAttend(Meeting *arr, int n) {
    if (n <= 1) {
        return 1; // True for 0 or 1 meeting
    }
    
    // 1. Sort the meetings by their start times
    // qsort(base_address, number_of_elements, size_of_each_element, comparison_function)
    qsort(arr, n, sizeof(Meeting), compareMeetings);
    
    // 2. Check for overlap by comparing consecutive meetings
    // 
    for (int i = 0; i < n - 1; i++) {
        // Compare the current meeting's end time with the next meeting's start time
        if (arr[i].end > arr[i + 1].start) {
            return 0; // Overlap found
        }
    }
    
    return 1; // No overlaps found
}

// --- Command Line Processing Function ---

int main(int argc, char *argv[]) {
    // Each meeting requires two arguments (start and end time)
    int n = (argc - 1) / 2; 

    if (n <= 0 || (argc - 1) % 2 != 0) {
        printf("Usage: %s <start1> <end1> <start2> <end2> ...\n", argv[0]);
        printf("Example: %s 2 4 1 2 7 8 5 6 6 8\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the array of Meeting structs
    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));
    if (meetings == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Populate the array from command-line arguments
    for (int i = 0; i < n; i++) {
        // argv[1] is the first start time, argv[2] is the first end time, etc.
        meetings[i].start = atoi(argv[2 * i + 1]);
        meetings[i].end = atoi(argv[2 * i + 2]);
    }

    // Perform the check
    int result = canAttend(meetings, n);

    // Print the result (C equivalent of C++'s ternary output)
    printf("%s\n", result ? "true" : "false");

    // Free the dynamically allocated memory
    free(meetings);

    return 0;
}