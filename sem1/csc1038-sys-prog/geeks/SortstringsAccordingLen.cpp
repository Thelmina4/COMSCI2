Sort an array of strings according to string lengths
Last Updated : 17 Jul, 2025
Given an array arr[] of strings, which needs to be sorted in ascending order based on the lengths of the strings. If two strings have the same length, their original relative order must be preserved in the final output.

Examples:

Input: arr[] = ["GeeksforGeeeks", "I", "from", "am"]
Output: ["I", "am", "from", "GeeksforGeeks"]
Explanation: The strings are sorted in increasing order of their lengths, starting from the shortest string "I" to the longest one "GeeksforGeeeks".

Input: arr[] = ["You", "are", "beautiful", "looking"]
Output: ["You", "are", "looking", "beautiful"]
Explanation: The strings are sorted by length: "You", "are", "looking", and then "beautiful", with the shortest words appearing first and the longest last.

Table of Content

[Approach 1] Stable Sort - O(nlogn) in Time and O(n) in Space
[Approach 2] Merge Sort - O(nlogn) in Time and O(n) in Space
[Approach 1] Stable Sort - O(nlogn) in Time and O(n) in Space
Using a custom comparator, which compares two strings by checking if the first string’s length is smaller than the second. The stable_sort ensures that if two strings have the same length, their original relative order is preserved.




#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
// Function to sort strings based on their length
void sortByLength(vector<string> &s)
{
    stable_sort(s.begin(), s.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
}
​
int main()
{
    vector<string> arr = {"GeeksforGeeks", "I", "from", "am"};
​
    sortByLength(arr);
​
    for (const string &str : arr)
        cout << str << " " ;
​
    return 0;
}

Output
I am from GeeksforGeeks 
[Approach 2] Merge Sort - O(nlogn) in Time and O(n) in Space
The main idea of this approach is to use the Merge Sort algorithm to sort a list of strings based on their lengths while maintaining their original order for strings of equal length, ensuring stability. The array is recursively divided into halves, and during the merge step, strings are compared by length and combined in sorted order.




#include <iostream>
#include <vector>
using namespace std ;
​
// Merge two halves in a stable way
void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1 ;
    int n2 = right - mid ;
​
    vector<string> L(n1), R(n2) ;
​
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
​
    int i = 0, j = 0, k = left;
​
    // Merge the two halves in a stable way (by length)
    while (i < n1 && j < n2) {
        if (L[i].length() <= R[j].length()) {
            arr[k++] = L[i++] ;
        } else {
            arr[k++] = R[j++] ;
        }
    }
​
    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++] ;
    }
​
    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++] ;
    }
}
​
// Merge Sort (recursive)
void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
​
        mergeSort(arr, left, mid) ;
        mergeSort(arr, mid + 1, right) ;
​
        merge(arr, left, mid, right) ;
    }
}
​
// Function to sort strings based on their length
void sortByLength(vector<string>& arr) {
    mergeSort(arr, 0, arr.size() - 1) ;
}
​
int main() {
    vector<string> arr = {"GeeksforGeeks", "I", "from", "am"} ;
​
    sortByLength(arr) ; 
​
    for (auto& s : arr)
        cout << s << " " ;
​
    return 0 ;
}

Output
I am from GeeksforGeeks 