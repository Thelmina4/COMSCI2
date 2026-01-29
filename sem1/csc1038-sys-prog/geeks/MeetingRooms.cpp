Meeting Rooms - Check if a person can attend all meetings
Last Updated : 15 Jul, 2025
Given a 2D array arr[][] where arr[i][0] represents the starting time and arr[i][1] represents the ending time of the ith meeting, determine whether it is possible for a person to attend all meetings without any overlaps, considering that a person can attend only one meeting at any given time.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

Examples:

Input: arr[][] = [[2, 4], [1, 2], [7, 8], [5, 6], [6, 8]]
Output: false
Explanation: Since the third and fifth meeting overlap, a person cannot attend all the meetings.

Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings. 

Table of Content

[Naive Approach] By checking all pairs of meetings - O(n^2) Time and O(1) Space
[Expected Approach] Using Sorting - O(n*log(n)) Time and O(1) Space
[Naive Approach] By checking all pairs of meetings - O(n^2) Time and O(1) Space
A person won't be able to attend all the meetings if any two meetings overlap with each other. So, we can use nested loops to iterate over all pairs of meetings and check if any pair of meetings overlap with each other. If no meetings overlap, then it is possible to attend all the meetings, else it is impossible to attend all the meetings.




#include <iostream>
#include <vector>
using namespace std;
​
// function to check if two meeting overlap
bool isOverlap(vector<int> &meet1, vector<int> &meet2) {
    return (meet1[0] >= meet2[0] && meet1[0] < meet2[1]) ||
           (meet2[0] >= meet1[0] && meet2[0] < meet1[1]); 
}
​
// function to check if a person can attend all the meetings
bool canAttend(vector<vector<int>> &arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
          
            // If any two meetings overlap, then a person 
            // cannot attend all the meetings
            if(isOverlap(arr[i], arr[j]))
              return false;
        }
    }
    return true;
}
​
int main() {
    vector<vector<int>> arr = {{2, 4}, {1, 2}, {7, 8}, {5, 6}, {6, 8}};
    cout << (canAttend(arr) ? "true" : "false");
    return 0;
}

Output
false
[Expected Approach] Using Sorting - O(n*log(n)) Time and O(1) Space
Check whether all meetings can be attended without time conflicts by first sorting the meeting intervals based on their start times. After sorting, it compares each meeting's end time with the next meeting's start time to detect any overlaps. If an overlap is found, it returns false, indicating a scheduling conflict. Otherwise, it returns true, meaning all meetings can be attended without overlaps.

check_if_a_person_can_attend_all_meetings_using_sorting_2.webpcheck_if_a_person_can_attend_all_meetings_using_sorting_2.webp





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
bool canAttend(vector<vector<int>> &arr) {
    int n = arr.size();
    
    // Sort the meetings by their start times
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; i++) {
      
        // Compare the current meeting's end time with the 
        // next meeting's start time to check for overlap
        if(arr[i][1] > arr[i + 1][0])
          return false;
    }
    return true;
}
​
int main() {
    vector<vector<int>> arr = {{2, 4}, {1, 2}, {7, 8}, {5, 6}, {6, 8}};
    cout << (canAttend(arr) ? "true" : "false");
    return 0;
}

Output
false