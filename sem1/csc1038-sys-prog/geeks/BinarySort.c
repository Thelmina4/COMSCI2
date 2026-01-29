Stable Binary Sort
Last Updated : 23 Jul, 2025
Given an array arr[] of integers, the task is to partition the array based on even and odd elements. The partition has to be stable, meaning the relative ordering of all even elements must remain the same before and after partitioning, and the same should hold true for all odd elements.

Note: For a binary array (containing only 0s and 1s), this partition process is equivalent to sorting the array.

Examples:

Input: arr[] = [1, 0, 1, 1, 0, 0]
Output: [0 ,0 ,0, 1, 1, 1]
Explanation: All even numbers came before the odd numbers.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [2, 4, 1, 3, 5]
Explanation: All even numbers [2, 4] came before the odd numbers [1, 3, 5], and the relative ordering was also same.

Input: arr[] = [-5, -2, 0, 4, 7, 9]
Output: [-2, 0, 4, -5, 7, 9]
Explanation: All even numbers [-2, 0, 4] came before the odd numbers [-5, 7, 9], and the relative ordering was also same.

The idea is to to use Naive Partitioning Algorithm, We use a temporary array to store the rearranged elements. We first iterate over the original array and add all the even elements to the temporary array, maintaining their original order. Next, we add all the odd elements to the temporary array in the same manner.

This guarantees that even elements appear before odd elements while preserving the relative order of similar elements. Finally, we copy the elements from the temporary array back into the original array.




// C program to partition the array into even 
// and odd elements using naive partition approach
#include <stdio.h>
#include <stdlib.h>
​
// Function for stable partitioning of even-odd(binary) array 
void partition(int arr[], int n) {
  
    // create a temporary array to store the elements
    int *temp = (int *)malloc(n * sizeof(int));
    int idx = 0;
    
    // First fill even elements into the temporary array
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) 
            temp[idx++] = arr[i];
    }
    
    // Now fill odd elements into the temporary array
    for (int i = 0; i < n; i++) {
        if (arr[i] & 1) 
            temp[idx++] = arr[i];
    }
    
    // copy the elements from temp to arr
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}
​
int main() {
    int arr[] = {-5, -2, 0, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    partition(arr, n);
    
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    return 0;
}

Output
-2 0 4 -5 7 9 
Time Complexity: O(n), for traversing the array.
Auxiliary Space: O(n), for temporary array.

