Sort an array in wave form
Last Updated : 22 Jul, 2025
Given a sorted array arr[] of integers (in ascending order), rearrange the elements in-place to form a wave-like array.
An array is said to be in wave form if it satisfies the following pattern: arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥ ...
In other words, every even-indexed element should be greater than or equal to its adjacent odd-indexed elements (if they exist).

Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [2, 1, 4, 3, 5]
Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.

Input: arr[] = [2, 4, 7, 8, 9, 10]
Output: [4, 2, 8, 7, 10, 9]
Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.

Try it on GfG Practice
redirect icon
[Approach] Adjacent Pair Swapping Method
The main idea of this approach is to rearrange it into a wave form by swapping adjacent elements in pairs.

Since, the elements are in increasing order. Then, by swapping every pair of adjacent elements (i.e., arr[0] with arr[1], arr[2] with arr[3], and so on), we create a pattern where:

Every even index i holds a value greater than or equal to its neighboring odd indices i - 1 and i + 1 (if they exist).
This guarantees the wave condition: arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥ ...
The sorted array ensures the numbers are close enough to form valid wave peaks and valleys, and the pairwise swaps are what enforce the pattern.




#include<stdio.h>
#include<stdlib.h>
​
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
​
void sortInWave(int arr[], int n){
    // swap adjacent elements
    for (int i=0; i<n-1; i += 2)
        swap(&arr[i], &arr[i+1]);
}
​
int main(){
    
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       printf("%d ",arr[i]);
    return 0;
}

Output
2 1 4 3 5 