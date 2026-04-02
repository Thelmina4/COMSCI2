Intersection of Two Sorted Arrays
Last Updated : 23 Jul, 2025
Given two sorted arrays a[] and b[], the task is to return intersection. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count duplicate elements and the result should contain items in sorted order.

Examples:

Input: a[] = {1, 1, 2, 2, 2, 4}, b[] = {2, 2, 4, 4}
Output: {2, 4}
Explanation: 2 and 4 are only common elements in both the arrays.

Input: a[] = {1, 2}, b[] = {3, 4}
Output: {}
Explanation: No common elements.

Input: a[] = {1, 2, 3}, b[] = {1, 2, 3}
Output: {1, 2, 3}
Explanation: All elements are common

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] Using Nested Loops - O(n*m) Time and O(1) Space
Approaches Same as Unsorted Arrays - Best Time O(n+m) and O(n) Space
[Expected Approach] Using Merge Step of Merge Sort - O(n+m) Time and O(1) Space
[Naive Approach] Using Nested Loops - O(n*m) Time and O(1) Space
Traverse through a[] and avoid duplicates while traversing. Since the arrays are sorted, we can avoid duplicates by matching with the previous element.
For every element of a[], check if it is in b[], If Yes, then add it to the result and do not traverse further in b[] to avoid duplicates.



#include <stdio.h>
​
// Function to find the intersection of two arrays
// It returns the result array containing the common elements
void intersection(int a[], int m, int b[], int n, int res[], int *res_size) {
​
    for (int i = 0; i < m; i++) {
​
        // Note that duplicates must be 
        // consecutive in a sorted array
        if (i > 0 && a[i - 1] == a[i])
            continue;
​
        // Since we are only searching distinct
        // elements of a[] in b[] and we break as 
        // soon we find a match, we get only
        // distinct elements in result
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                res[(*res_size)++] = a[i];
                break;
            }
        }
    }
}
​
int main() {
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};
    int res[10];
    int res_size = 0; 
​
    intersection(a, 8, b, 5, res, &res_size);
​
    for (int i = 0; i < res_size; i++) {
        printf("%d ", res[i]);
    }
​
    return 0;
}

Output
5 10 15 
Approaches Same as Unsorted Arrays - Best Time O(n+m) and O(n) Space
We have discussed different approaches for intersection of unsorted arrays. We can use the same approaches here. The best performance that we can achieve using the same approaches is O(n+m) Time and O(n) Auxiliary Space for hash set. Please note that in these approaches we do not use the fact that input arrays are sorted.

[Expected Approach] Using Merge Step of Merge Sort - O(n+m) Time and O(1) Space
The idea is based one merge function to merge two sorted arrays.

We simultaneously traverse both a[] and b[] from the left side. While traversing, we avoid duplicates in a[]. We do not need to do it for b[] because once we have a match, we move ahead in a[] and b[] both.
If current elements are not same, we skip the smaller of the two. If current element of a[] is smaller, we move ahead in a[] and if current of b[] is smaller, we move ahead in b[].
Else (If same), we add one occurrence of the current element to the result and move ahead in both a[] and b[].
Intersection-of-two-sorted-arrays-5.webpIntersection-of-two-sorted-arrays-5.webp





#include <stdio.h>
​
// Function to find the intersection of two arrays
void intersection(int a[], int m, int b[], int n, int res[], int *res_size) {
    int i = 0, j = 0;
​
    // This is similar to merge of merge sort
    while (i < m && j < n) {
​
        // Skip duplicate elements in the first array
        if (i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
​
        // Skip the smaller
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        }
​
        // If equal, add to result and move both
        else {
            res[(*res_size)++] = a[i];
            i++;
            j++;
        }
    }
}
​
int main() {
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};
    int res[10];
    int res_size = 0;
​
    // Correctly call the intersection function
    intersection(a, 8, b, 5, res, &res_size);
​
    for (int i = 0; i < res_size; i++) {
        printf("%d ", res[i]);
    }
​
    return 0;
}

Output
5 10 15 