// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109



#include <iostream>
#include <vector>
using namespace std;
// Method 1: Linear Search Method.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        int f=-1,l=-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                f = i;
                break;
            }
            
        }
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] == target){
                l = i; break;
            }
        }
        return {f,l};
    }
};

// Method 2: Using Binary Search Method.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        int f=0,l=nums.size() - 1,mid,v1 = -1, v2 = -1;
        while(f<=l){
            mid = f + (l - 1 - f)/2;
            if(nums[mid] == target){
                v1 = mid;
                l = mid - 1;
               
            } else if(nums[mid] < target){
                f = mid + 1;
            } else if(nums[mid] > target){
                l = mid - 1;
            }
        }
        int f1=0,l1=nums.size() - 1,mid1;
        while(f1 <= l1){
            mid1 = f1 + (l1 - f1)/2;
            if(nums[mid1] == target){
                v2 = mid1;
                f1 = mid1 + 1;
            } else if(nums[mid1] < target){
                f1 = mid1 + 1;
            } else if(nums[mid1] > target){
                l1 = mid1 - 1;
            }
        }
        return {v1,v2};
    }
};
