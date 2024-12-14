// 33. Search in Rotated Sorted Array
// Solved
// Medium
// Topics
// Companies
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

#include <vector>

// Method 1: BruteForce Approach.
class Solution {
public:
    int search(vector<int>& nums, int target) {
       
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

// Method 2: Binary Search Method.
class Solution {
    public:
        int search(vector<int>& nums, int target){
            ios_base::sync_with_stdio(false);
            int f = 0, l = nums.size()-1, mid;
            while(f <= l){
                mid = f + (l - f)/2;
                if(nums[mid] == target){
                    return mid;
                } else if(nums[mid] >= nums[f]){
                    if(target < nums[mid] && target >= nums[f]){
                        l = mid - 1;
                    } else{
                        f = mid + 1;
                    }
                } else {
                    if(target > nums[mid] && target <= nums[l]){
                        f = mid + 1;
                    } else {
                        l = mid - 1;
                    }
                }
            }
            return -1;
        }
};