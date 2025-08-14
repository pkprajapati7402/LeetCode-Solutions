/*
169. Majority Element
Solved
Easy
Topics
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

*/

// Solution using Moore's Algorithm for Voting.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using Moore's Voting Algo.
        int n = nums.size();
        int cand = nums[0], count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                cand = nums[i];
                count++;
            } else{
                if(nums[i] == cand){
                    count++;
                } else{
                    count--;
                }
            }
        }
        return cand;
    }
};
