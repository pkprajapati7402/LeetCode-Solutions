/*
74. Search a 2D Matrix
Solved
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;  
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0, end = rows * cols - 1;  

        while (start <= end) {
            int mid = start + (end - start) / 2;
            // Using Row major method for Index value - > coordinate (i,j) value in 2d matrix.
            // row index(i) = Index / column.
            // column index(j) = Index % column.
            int midvalue = matrix[mid / cols][mid % cols];  

            if (midvalue == target) {
                return 1;  
            } else if (midvalue < target) {
                start = mid + 1;  
            } else {
                end = mid - 1;  
            }
        }

        return 0;  
    }
};
