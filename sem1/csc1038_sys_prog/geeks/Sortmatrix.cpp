Sort the given matrix
Last Updated : 22 Oct, 2024
Given a m x n matrix. The problem is to sort the given matrix in strict order. Here strict order means that the matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= m-1, the first element is greater than or equal to the last element of row 'i-1'.

Untitled-Diagram601
Examples: 

Input : mat[][] = { {5, 4, 7},
                              {1, 3, 8},
                              {2, 9, 6} }
Output : 1 2 3
               4 5 6
               7 8 9

Input: mat[][] = { {5, 4, 7}, 
                               {1, 3, 8} }
Output: 1 3 4        
              5 7 8

Try it on GfG Practice
redirect icon
Naive Approach - O(mn Log mn) Time and O(mn) Space
We first store the matrix elements in a m x n sized 1D array, then sort the array and finally copy the elements back to the matrix,




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
void sortMatrix(vector<vector<int>>& mat) {
    vector<int> temp;
    
    // Collect all elements in a temporary vector
    for (auto& row : mat) {
        for (int x : row) {
            temp.push_back(x);
        }
    }
    
    // Sort the vector
    sort(temp.begin(), temp.end());
    
    // Put sorted values back into the matrix
    int k = 0;
    for (auto& row : mat) {
        for (int& x : row) {
            x = temp[k++];
        }
    }
}
​
int main() {
    vector<vector<int>> mat{{5, 4, 7}, {1, 3, 8}, {2, 9, 6}};
    
    sortMatrix(mat);
    
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

Output
Sorted Matrix Will be:
1 2 3 
4 5 6 
7 8 9 
Time Complexity: O(mnlog2mn)
Auxiliary Space: O(mn) for the auxiliary 1D array.

Treating the Given Array as 1D Array - O(1) Space
The idea is to treat the 2D-Array as a 1D-Array to sort the matrix without using extra space. This can also be explained with the help of the following example. 

For Example:

There is a 2*2 Matrix with 4 elements,
The idea is to treat the elements of the matrix
as 1D Array of 4 elements.
1 2
3 4

As In the given matrix each element can be accessed as -
1st Element - 0th Row, 0th Col
2nd Element - 0th Row, 1st Col
3rd Element - 1st Row, 0th Col
4th Element - 1st Row, 1st Col 