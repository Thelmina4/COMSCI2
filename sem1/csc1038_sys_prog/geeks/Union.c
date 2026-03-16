Union of Two Sorted Arrays
Last Updated : 23 Jul, 2025
Given two sorted arrays a[] and b[], the task is to return union of both the arrays in sorted order. Union of two arrays is an array having all distinct elements that are present in either array. The input arrays may contain duplicates.

Examples:

Input: a[] = {1, 1, 2, 2, 2, 4}, b[] = {2, 2, 4, 4}
Output: {1, 2, 4}
Explanation: 1, 2 and 4 are the distinct elements present in either array.

Input: a[] = {3, 5, 10, 10, 10, 15, 15, 20}, b[] = {5, 10, 10, 15, 30}
Output: {3, 5, 10, 15, 20, 30}
Explanation: 3, 5, 10, 15, 20 and 30 are the distinct elements present in either array.

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] Using Nested Loops – O(n*m) Time and O(1) Space
[Better Approach] Using Set – O((n+m)*(log (n+m))) Time and O(n+m) Space
[Expected Approach] Using Merge Step of Merge Sort - O(n+m) Time and O(1) Space
[Naive Approach] Using Nested Loops – O(n*m) Time and O(1) Space
The intuition behind this approach is to gather unique elements from two arrays by checking each element against the current result array. The idea is to traverse both the arrays and for each element, check if the element is present in the result or not. If not, then add this element to the result.




// C program to find union of two sorted arrays
// using nested loops
​
#include <stdio.h>
#include <stdlib.h>
​
// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
​
// Function to find union of two sorted arrays
int* findUnion(int a[], int n, int b[], int m, int* size) {
    int* res = (int*)malloc((m + n) * sizeof(int));
    int index = 0;
​
    // Traverse through a[] and search every element
    // a[i] in result
    for (int i = 0; i < n; i++) {
      
        // Check if the element is already in the result to avoid duplicates
        int j;
        for (j = 0; j < index; j++) {
            if (res[j] == a[i]) 
                break;
        }
        if (j == index)
            res[index++] = a[i];
    }
​
    // Traverse through b[] and search every element
    // b[i] in result
    for (int i = 0; i < m; i++) {
      
        // Check if the element is already in the result to avoid duplicates
        int j;
        for (j = 0; j < index; j++) {
            if (res[j] == b[i]) 
                break;
        }
        if (j == index)
            res[index++] = b[i];
    }
​
    // Sort the result array using qsort
    qsort(res, index, sizeof(int), compare);
​
    *size = index; 
    return res; 
}
​
int main() {
    int a[] = {1, 1, 2, 2, 2, 4};
    int b[] = {2, 2, 4, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int size;
​
    int* result = findUnion(a, n, b, m, &size);
  
    for (int i = 0; i < size; i++) 
        printf("%d ", result[i]);
    
    free(result); 
    return 0;
}

Output
1 2 4 
Time Complexity: O((n + m)2), where n is size of a[] and m is size of b[]

Copying all elements from a[] to res[] takes O(n2) time.
Now in the worst case, there will be no common elements in a[] and b[]. So, to check if the first element of b[] is present in res[], we need n comparisons. Similarly, for second element of b[], we need (n + 1) comparisons. So for m elements, total number of comparisons will be: n + (n + 1) + (n + 2) …. (n + m) = (n * m) + (m2 / 2)
So, overall time complexity = O(n2 + n * m + m2)
Auxiliary Space: O(1)

[Better Approach] Using Set – O((n+m)*(log (n+m))) Time and O(n+m) Space
The approach is to insert all elements from both arrays, a[] and b[], into a set. Since a set automatically removes duplicates, it gives us the union of the two arrays. Also, the set keeps the elements in sorted order, so after inserting them, we can store these sorted and unique elements in a result array.

Note: In Python and JavaScript, the set data structure does not store the elements in sorted order, so we need to explicitly sort the union array.




// C++ program to find union of two sorted arrays using Set
​
#include <iostream>
#include <set>
#include <vector>
using namespace std;
​
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    set<int> st;
​
    // Put all elements of a[] in st
    for (int i = 0; i < a.size(); i++)
        st.insert(a[i]);
​
    // Put all elements of b[] in st
    for (int i = 0; i < b.size(); i++)
        st.insert(b[i]);
​
    vector<int> res;
​
    // iterate through the set to fill the result array
    for (auto it : st)
        res.push_back(it);
    return res;
}
​
int main() {
​
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
​
    vector<int> res = findUnion(a, b);
​
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
​
    return 0;
}

Output
1 2 4 