/*
59. Spiral Matrix II
Solved
Medium
Topics
Companies
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n));

        int counter = 1;
        int left = 0, right = n -1, top = 0, bottom = n - 1;
        while(left <= right && top <= bottom){
            // Top layer.
            for(int i = left; i <= right; i++){
                arr[top][i] = counter;
                counter++;
            }
            top++;
            // Left Layer.
            for(int i = top; i <= bottom; i++){
                arr[i][right] = counter;
                counter++;
            }
            right--;
            // Bottom with validity.
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    arr[bottom][i] = counter;
                    counter++;
                }
                bottom--;
            }
            // Left with validity.
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    arr[i][left]  = counter;
                    counter++;
                }
                left++;
            }
        }
        return arr;
};