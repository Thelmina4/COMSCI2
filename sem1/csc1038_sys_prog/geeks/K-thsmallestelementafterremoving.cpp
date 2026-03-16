K-th smallest element after removing some integers from natural numbers
Last Updated : 23 Jul, 2025
Given an array arr[] of size 'n' and a positive integer k. Consider series of natural numbers and remove arr[0], arr[1], arr[2], ..., arr[n-1] from it. Now the task is to find k-th smallest number in the remaining set of natural numbers. If no such number exists print "-1".

Examples :  

Input: arr[] = [ 1 ] and k = 1.
Output: 2
Explanation: Natural numbers are {1, 2, 3, 4, .... }. After removing {1}, we get {2, 3, 4, ...}. Now, 2-th smallest element = 2.

Input: arr[] = [ 1, 3 ], k = 4.
Output:  6
Explanation: First 5 Natural number {1, 2, 3, 4, 5, 6,  .. }. After removing {1, 3}, we get {2, 4, 5, 6, ... }.Now, 4-th smallest element = 6.''

In this article we have discussed the Naive approach in detail, this problem can be solved in more efficient ways. You can find them here K-th smallest element after removing given integers from natural numbers | Set 2

[Naive Approach] Using Nested Loop – O(n * k) Time and O(1) Space
Iterate Over Natural Numbers: We start from 1 and check each number to see if it’s in the arr[] (i.e., removed).
Check if Number is to be Removed: For each natural number, we use a nested loop to check if it exists in the removed numbers list (arr[]).
Count Valid Numbers: If the number is not found in the removed list, it’s counted as a valid number.
Return the k-th Valid Number: When we’ve counted k valid numbers, return the current number.



ing namespace std;
int findkthSmall(const vector<int>& arr, int k) {
    int cnt = 0, num = 1;
    while (cnt < k) {
        bool isValid = true;

        // Check if the number is removed
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cnt++;
        }
        num++;
    }
    return num - 1; 
}

int main() {
    vector<int> arr = {1};
    int k = 1;
    cout << findkthSmall(arr, k) << endl;  
}
#include <bits/stdc++.h>
using namespace std;
int findkthSmall(const vector<int>& arr, int k) {
    int cnt = 0, num = 1;
    while (cnt < k) {
        bool isValid = true;
​
        // Check if the number is removed
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cnt++;
        }
        num++;
    }
    return num - 1; 
}
​
int main() {
    vector<int> arr = {1};
    int k = 1;
    cout << findkthSmall(arr, k) << endl;  
}

Output
2