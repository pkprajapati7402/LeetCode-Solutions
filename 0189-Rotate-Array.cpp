// 189. Rotate Array
// Attempted
// Medium
// Topics
// Companies
// Hint
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 

// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// Method 1:

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n; // To handle cases where k > n
        
        // Rotate k times
        for(int i = 0; i < k; i++) {
            // Store the last element
            int last = a[n - 1];
            // Shift all elements to the right by one position
            for(int j = n - 1; j > 0; j--) {
                a[j] = a[j - 1];
            }
            // Place the last element at the first position
            a[0] = last;
        }
    }
};


// Method 2: Using functions.
class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n; // To handle cases where k > n
        
        // Reverse the entire array
        reverse(a.begin(), a.end());
        
        // Reverse the first k elements
        reverse(a.begin(), a.begin() + k);
        
        // Reverse the remaining n - k elements
        reverse(a.begin() + k, a.end());
    }
};


// Method 2: Updated


class Solution {
public:
    void rotate(vector<int>& a, int k) {
        ios_base::sync_with_stdio(false);
        int n = a.size();
        k = k % n; 
        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin() + k);
        reverse(a.begin() + k, a.end());
    }
};
