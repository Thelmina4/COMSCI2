Two Sum - Pair sum in sorted array
Last Updated : 25 Aug, 2025
Given a 1-based indexed integer array arr[] that is sorted in non-decreasing order, along with an integer target. find two elements in the array such that their sum is equal to target. If such a pair exists, return the indices of the two elements in increasing order. If no such pair exists, return [-1, -1].

Examples:

Input: arr[] = [2, 7, 11, 15], target = 9
Output: 1 2
Explanation: Since the array is 1-indexed, arr[1] + arr[2] = 2 + 7 =  9

Input: arr[] = [1, 3, 4, 6, 8, 11] target = 10
Output: 3 4
Explanation: Since the array is 1-indexed, arr[3] + arr[5] = 4 + 6 = 10

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] Try all Pairs - O(n^2) Time and O(1) Space
[Expected Approach] Using Two Pointers - O(n) Time and O(1) Space
[Naive Approach] Try all Pairs - O(n^2) Time and O(1) Space
The idea is to check every possible pair of elements using two nested loops. If any pair adds up to the target, we return their 1-based indices immediately.




#include <iostream>
#include <vector>
using namespace std;
​
vector<int> twoSum(vector<int> &arr, int target){
    int n = arr.size();
    // finding all possible pairs
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return {i+1, j+1};
            }
        }
    }
    // no pair sum with given target
    return {-1, -1};
}
​
int main() {
    vector<int> arr = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = twoSum(arr, target);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

Output
1 2 
[Expected Approach] Using Two Pointers - O(n) Time and O(1) Space
The problem can be solved using two pointers technique. We can maintain two pointers, left = 0 and right = n - 1, and calculate their sum S = arr[left] + arr[right]. 

If S = target, then return left and right.
If S < target, then we need to increase sum S, so we will increment left = left + 1.
If S > target, then we need to decrease sum S, so we will decrement right = right - 1.
If at any point left >= right, then no pair with sum = target is found.

Step-by-step algorithm:

We need to initialize two pointers as left and right with position at the beginning and at the end of the array respectively.
Need to calculate the sum of the elements in the array at these two positions of the pointers.
If the sum equals to target value, return the 1-indexed positions of the two elements.
If the sum comes out to be less than the target, move the left pointer to the right to the increase the sum.
If the sum is greater than the target, move the right pointer to the left to decrease the sum.
Repeat the following steps till both the pointers meet.



#include <iostream>
#include <vector>
using namespace std;
​
vector<int> twoSum(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;
​
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        // If current sum = target, return left and right
        if (current_sum == target) {
            return { left + 1, right + 1 };
        }
        // If current sum < target, then increase the
        // current sum by moving the left pointer by 1
        else if (current_sum < target) {
            left++;
        }
        else {
            // If current sum > target, then decrease the
            // current sum by moving the right pointer by 1
            right--;
        }
    }
​
    // no pair sum with given target
    return { -1, -1 };
}
​
int main(){
    vector<int> arr = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = twoSum(arr, target);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

Output
1 2 