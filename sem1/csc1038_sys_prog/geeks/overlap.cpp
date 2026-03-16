Check if any two intervals intersect in a given set
Last Updated : 26 Mar, 2025
An interval is represented as a combination of start time and end time. Given a set of intervals, check if any two intervals intersect. 

Examples: 

Input:  arr[] = [[1, 3], [5, 7], [2, 4], [6, 8]]
Output: True
Explanation: The intervals {1, 3} and {2, 4} overlap

Input:  arr[] = [[1, 3], [7, 9], [4, 6], [10, 13]]
Output: False
Explanation: No pair of intervals overlap. 

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] - Using Nested Loops - O(n ^ 2) Time and O(1) Space
[Expected Approach] - Using Sorting - O(n * log n) Time and O(1) Space
[Alternate Approach] - Using Prefix Sum
[Naive Approach] - Using Nested Loops - O(n ^ 2) Time and O(1) Space
The idea is to consider every pair of intervals and check if the pair intersects or not. To do so, run a nested loops, where the outer loop marks the current interval and for each iteration of outer loops, the inner loop traverse through each interval and checks if any of the interval intersects.




#include <bits/stdc++.h>
using namespace std;
​
// Function to check if any two intervals
// intersect with each other
bool isIntersecting(vector<int> a, vector<int> b) {
    if (a[1] < b[0] || b[1] < a[0])
        return false;
    return true;
}
​
// Function to check if any two intervals
// in the given list intersect with each other
bool isIntersect(vector<vector<int>> intervals) {
    int n = intervals.size();
​
    // Iterate over all pairs of intervals
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
​
            // check, if two intervals intersect
            if (isIntersecting(intervals[i], intervals[j]))
                return true;
        }
    }
    return false;
}
​
int main() {
    vector<vector<int>> intervals = {{1, 3}, {5, 7}, {2, 4}, {6, 8}};
    if (isIntersect(intervals))
        cout << "True";
    else
        cout << "False";
    return 0;
}

Output
True
[Expected Approach] - Using Sorting - O(n * log n) Time and O(1) Space
The idea is to sort the given list of intervals in the increasing order of start time. For each interval, check if the start time of current interval is less than or equal to the end time of previous interval, if so, return "True". If no such interval is found, return "False".




#include <bits/stdc++.h>
using namespace std;
​
// Function to check if any two intervals
// in the given list intersect with each other
bool isIntersect(vector<vector<int>> intervals) {
    int n = intervals.size();
​
    // sort the intervals based on the starting time
    sort(intervals.begin(), intervals.end());
​
    // check if any of the interval 
    // intersects with its previous
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= intervals[i - 1][1])
            return true;
    }
​
    return false;
}
​
int main() {
    vector<vector<int>> intervals = {{1, 3}, {5, 7}, {2, 4}, {6, 8}};
    if (isIntersect(intervals))
        cout << "True";
    else
        cout << "False";
    return 0;
}

Output
True