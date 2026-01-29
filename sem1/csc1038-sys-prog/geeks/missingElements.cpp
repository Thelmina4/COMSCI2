Find missing elements of a range
Last Updated : 23 Oct, 2024
Given an array, arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in a range, but not the array. The missing elements should be printed in sorted order.

Examples:  

Input: arr[] = {10, 12, 11, 15}, 
       low = 10, high = 15
Output: 13, 14

Input: arr[] = {1, 14, 11, 51, 15}, 
       low = 50, high = 55
Output: 50, 52, 53, 54 55

Try it on GfG Practice
redirect icon
Naive Approach - O(n^2) Time and O(1) Space
The naive approach for the problem can be to use two nested loops: one to traverse numbers from low to high and other one to traverse entire array to find out whether the element of the outer  loop exists in the array or not. If it doesn't exist we will print it else continue to next iteration.




// C++ code for the approach
​
#include <bits/stdc++.h>
using namespace std;
​
// Function to find and print missing 
// elements in the given range
void findMissing(int arr[], int n, int low, int high) {
    // Loop through the range of numbers from low to high
    for (int i = low; i <= high; i++) {
        bool found = false;
      
        // Loop through the array to check if i exists in it
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
      
        // If i is not found in the array, print it
        if (!found) {
            cout << i << " ";
        }
    }
}
​
// Driver's code
int main() {
      // Input array
    int arr[] = { 1, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
  
      // Function call
    findMissing(arr, n, low, high);
    return 0;
}

Output
2 6 7 8 9 10 


Better Approach - Sorting - O(n Log n) Time and O(1) Space
Sort the array, then do a binary search for 'low'. Once the location of low is found, start traversing the array from that location and keep printing all missing numbers.




// A sorting based C++ program to find missing
// elements from an array
#include <bits/stdc++.h>
using namespace std;
​
// Print all elements of range [low, high] that
// are not present in arr[0..n-1]
void printMissing(int arr[], int n, int low,
                  int high)
{
    // Sort the array
    sort(arr, arr + n);
​
    // Do binary search for 'low' in sorted
    // array and find index of first element
    // which either equal to or greater than
    // low.
    int* ptr = lower_bound(arr, arr + n, low);
    int index = ptr - arr;
​
    // Start from the found index and linearly
    // search every range element x after this
    // index in arr[]
    int i = index, x = low;
    while (i < n && x <= high) {
        // If x doesn't match with current element
        // print it
        if (arr[i] != x)
            cout << x << " ";
​
        // If x matches, move to next element in arr[]
        else
            i++;
​
        // Move to next element in range [low, high]
        x++;
    }
​
    // Print range elements that are greater than the
    // last element of sorted array.
    while (x <= high)
        cout << x++ << " ";
}
​
// Driver program
int main()
{
    int arr[] = { 1, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
    printMissing(arr, n, low, high);
    return 0;
}

Output
2 6 7 8 9 10 
Expected Approach 1 - Using Boolean Array - O(n + high - low + 1) Time and O(high - low + 1) Space
Create a boolean array, where each index will represent whether the (i+low)th element is present in the array or not. Mark all those elements which are in the given range and are present in the array. Once all array items present in the given range have been marked true in the array, we traverse through the Boolean array and print all elements whose value is false.




// An array based C++ program
// to find missing elements from
// an array
#include <bits/stdc++.h>
using namespace std;
​
// Print all elements of range
// [low, high] that are not present
// in arr[0..n-1]
void printMissing(
    int arr[], int n,
    int low, int high)
{
    // Create boolean array of size
    // high-low+1, each index i representing
    // whether (i+low)th element found or not.
    bool points_of_range[high - low + 1] = { false };
​
    for (int i = 0; i < n; i++) {
        // if ith element of arr is in
        // range low to high then mark
        // corresponding index as true in array
        if (low <= arr[i] && arr[i] <= high)
            points_of_range[arr[i] - low] = true;
    }
​
    // Traverse through the range and
    // print all elements  whose value
    // is false
    for (int x = 0; x <= high - low; x++) {
        if (points_of_range[x] == false)
            cout << low + x << " ";
    }
}
​
// Driver program
int main()
{
    int arr[] = { 1, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
    printMissing(arr, n, low, high);
    return 0;
}
​
// This code is contributed by Shubh Bansal

Output
2 6 7 8 9 10 
Expected Approach 2 - Use Hashing - O(n + high - low + 1) Time and O(n) Space
Create a hash table and insert all array items into the hash table. Once all items are in hash table, traverse through the range and print all missing elements.




// A hashing based C++ program to find missing
// elements from an array
#include <bits/stdc++.h>
using namespace std;
​
// Print all elements of range [low, high] that
// are not present in arr[0..n-1]
void printMissing(int arr[], int n, int low,
                  int high)
{
    // Insert all elements of arr[] in set
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
​
    // Traverse through the range an print all
    // missing elements
    for (int x = low; x <= high; x++)
        if (s.find(x) == s.end())
            cout << x << " ";
}
​
// Driver program
int main()
{
    int arr[] = { 1, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
    printMissing(arr, n, low, high);
    return 0;
}

Output
2 6 7 8 9 10 
