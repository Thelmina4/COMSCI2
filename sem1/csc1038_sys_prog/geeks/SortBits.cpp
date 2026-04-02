Sort an array according to count of set bits
Last Updated : 10 Mar, 2025
Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

Examples:

Input: arr[] = [5, 2, 3, 9, 4, 6, 7, 15, 32]
Output: 15 7 5 3 9 6 2 4 32
Explanation: The integers in their binary representation are:
    15 -1111
    7  -0111
    5  -0101
    3  -0011
    9  -1001
    6  -0110
    2  -0010
    4- -0100
    32 -10000
Hence the non-increasing sorted order is: {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}.

Input: arr[] = [1, 2, 3, 4, 5, 6]
Output: 3 5 6 1 2 4
Explanation: The integers in their binary representation are:
    3  - 0011
    5  - 0101
    6  - 0110
    1  - 0001
    2  - 0010
    4  - 0100
hence the non-increasing sorted order is {3, 5, 6}, {1, 2, 4}.

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] - Using Insertion Sort - O(n ^ 2) Time and O(n) Space
[Better Approach] - Using Inbuilt Sort Function - O(n * log n) Time and O(1) Space
[Expected Approach] - Using Counting Sort - O(n) Time and O(n) Space
[Alternate Approach] - Using Multimap - O(n * log n) Time and O(n) Space
[Naive Approach] - Using Insertion Sort - O(n ^ 2) Time and O(n) Space
The idea is to store the set-bit counts of all the integers in the auxiliary array and simultaneously sort both arrays according to the non-increasing order of auxiliary array.




#include <bits/stdc++.h>
using namespace std;
​
// Function to simultaneously sort both 
// arrays using insertion sort
void insertionSort(vector<int> &arr, vector<int> &bitCnt) {
    int n = arr.size();
​
    for (int i = 1; i < n; i++) {
        int key1 = bitCnt[i];
        int key2 = arr[i];
        int j = i - 1;
​
        while (j >= 0 && bitCnt[j] < key1) {
            bitCnt[j + 1] = bitCnt[j];
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        bitCnt[j + 1] = key1;
        arr[j + 1] = key2;
    }
}
​
// Function to count set bits in an integer
int countBits(int a) {
    int count = 0;
    while (a) {
        if (a % 2 != 0)
            count += 1;
        a = a / 2;
    }
    return count;
}
​
// Function to sort an array according to bit count
void sortBySetBitCount(vector<int>& arr) {
    int n = arr.size();
​
    // Create an array and store 
    // count of set bits in it.
    vector<int> bitCnt(n);
    for (int i = 0; i < n; i++)
        bitCnt[i] = countBits(arr[i]);
    
    // sort the array 
    insertionSort(arr, bitCnt);
}
​
int main() {
    vector<int> arr = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    sortBySetBitCount(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

Output
15 7 5 3 9 6 2 4 32 
[Better Approach] - Using Inbuilt Sort Function - O(n * log n) Time and O(1) Space
The idea is to use the inbuilt sort function and custom comparator to sort the array according to set-bit count. 




#include <bits/stdc++.h>
using namespace std;
​
// Function to count set bits in an integer
int countBits(int a) {
    int count = 0;
    while (a) {
        if (a % 2 != 0)
            count += 1;
        a = a / 2;
    }
    return count;
}
​
// custom comparator of std::sort
bool cmp(int a, int b) {
    int count1 = countBits(a);
    int count2 = countBits(b);
​
    // this takes care of the stability of sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}
​
// Function to sort an array according to bit count
void sortBySetBitCount(vector<int>& arr) {
    stable_sort(arr.begin(), arr.end(), cmp);
}
​
int main() {
    vector<int> arr = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    sortBySetBitCount(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

Output
15 7 5 3 9 6 2 4 32 
[Expected Approach] - Using Counting Sort - O(n) Time and O(n) Space
The idea is to use counting sort to arrange the elements in descending order of count of set-bits. For any integer, assuming the minimum and maximum set-bits can be 1 and 31 respectively, create an array count[][] of size 32, where each element count[i] stores the elements of given array with count of their set bits equal to i. After inserting all the elements, traverse count[][] in reverse order, and store the elements at each index in the given array.

Capture




#include <bits/stdc++.h>
using namespace std;
​
// Function to count set bits in an integer
int countBits(int a) {
    int count = 0;
    while (a) {
        if (a % 2 != 0)
            count += 1;
        a = a / 2;
    }
    return count;
}
​
// Function to sort an array according to bit count
void sortBySetBitCount(vector<int>& arr) {
    int n = arr.size();
​
    // Create a 2d array to map array elements
    // to their corresponding set bit count
    vector<vector<int>> count(32);
​
    // insert elements in the 2d array
    for (int i=0; i<n; i++) {
        int setBit = countBits(arr[i]);
        count[setBit].push_back(arr[i]);
    }
​
    // to track the index of sorted array
    int j = 0;
​
    // Traverse through all bit counts
    for (int i = 31; i >= 0; i--) {
​
        // Traverse through all elements 
        // of current bit count
        for(int k = 0; k < count[i].size(); k++) {
            arr[j++] = count[i][k];
        }
    }
}
​
int main() {
    vector<int> arr = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    sortBySetBitCount(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

Output
15 7 5 3 9 6 2 4 32 
[Alternate Approach] - Using Multimap - O(n * log n) Time and O(n) Space
The idea is store the elements corresponding to negative (to ensure elements are sorted in descending order) of their count of set-bits in a multimap.

Create a MultiMap whose key values will be the negative of the number of set-bits of the element.
Traverse the array and do following for each element:
Count the number set-bits of this element. Let it be 'setBitCount'
count.insert({(-1) * setBitCount, element})
Traverse 'count' and print the second elements.



#include <bits/stdc++.h>
using namespace std;
​
// Function to count set bits in an integer
int countBits(int a) {
    int count = 0;
    while (a) {
        if (a % 2 != 0)
            count += 1;
        a = a / 2;
    }
    return count;
}
​
// Function to sort an array according to bit count
void sortBySetBitCount(vector<int>& arr) {
    int n = arr.size();
​
    // to map the elements to their
    // corresponding set bit count
    multimap<int, int> count;
  
    // Iterate over all values and 
    // insert into multimap
    for( int i = 0 ; i < n ; i++ ) {
        count.insert({(-1) * countBits(arr[i]), arr[i]});
    }
    
    int j = 0;
  
    // Iterate over all values and
    // insert into the array
    for(auto i: count) {
        arr[j++] = i.second;
    }
}
​
int main() {
    vector<int> arr = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    sortBySetBitCount(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

Output
15 7 5 3 9 6 2 4 32 