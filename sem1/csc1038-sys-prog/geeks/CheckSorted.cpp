Check if an Array is Sorted
Last Updated : 18 Oct, 2025
Given an array arr[], check if it is sorted in ascending order or not. Equal values are allowed in an array and two consecutive equal values are considered sorted.

Examples: 

Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.

Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false
Explanation: The given array is not sorted.

Try it on GfG Practice
redirect icon
Table of Content

[Approach 1] Recursive approach - O(n) Time and O(n) Space
[Approach 2] Iterative approach - O(n) Time and O(1) Space
[Approach 2] Using Built-in Methods (Applicable for C++ and Python Only) - O(n) Time and O(1) Space
[Approach 1] Recursive approach - O(n) Time and O(n) Space
The idea behind recursive approach is check if the first two elements are in order, then recursively check the rest of the array. The base case is when the array has zero or one element, which is always considered sorted.

Step-By-Step Approach:  

If size of array is zero or one, return true.
Check last two elements of array, if they are sorted, perform a recursive call with n-1 else, return false.



#include <stdio.h>
#include <stdbool.h>
​
// Helper function that takes array and size, used for recursion
bool isSortedHelper(int arr[], int n) {
    if (n == 0 || n == 1)
        return true;
    return arr[n - 1] >= arr[n - 2] && isSortedHelper(arr, n - 1);
}
​
// Main function to check if array is sorted, only takes array as input
bool isSorted(int arr[], int size) {
    return isSortedHelper(arr, size);
}
​
int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%s\n", isSorted(arr, size) ? "true" : "false");
    return 0;
}

Output
true
[Approach 2] Iterative approach - O(n) Time and O(1) Space
The idea is simple. We start traversing from the second element. For every element we check if it is smaller than or equal to previous element or not. At any point if we find previous element greater, we return false. 

For example: arr[] = [10, 20, 30, 5, 6]

i = 1 : (10 <= 20), continue
i = 2 : (20 <= 30), continue
i = 3 : (30 > 5), return false.




#include <stdio.h>
#include <stdbool.h>
​
bool isSorted(int arr[], int n) {
    
     // Iterate over the array and check if 
    // every element is greater than or
    // equal to previous element.
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i])
            return false;
    }
​
    return true;
}
​
int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
​
    if (isSorted(arr, n))
        printf("true\n");
    else
        printf("false\n");
​
    return 0;
}

Output
true