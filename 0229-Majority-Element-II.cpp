/*
229. Majority Element II
Attempted
Medium
Topics
Companies
Hint
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?


*/

// Approach. as the majority element is greater than n/3. So maximum elements thats in majority is 2.
// Considering 2 candidate elements, and finding them in the array.
// couting their repetition, and verifying.
// Moore's Voting Algorithm.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand2, count1 = 0, count2 = 0;
        int n = nums.size();
        // Finding Candidates.
        for(int num : nums){
            if(num == cand1){
                count1++;
            } else if(num == cand2){
                count2++;
            } else if(count1 == 0){
                cand1 = num;
                count1++;
            } else if(count2 == 0){
                cand2 = num;
                count2++;
            } else{
                count1--;
                count2--;
            }
        }
        // Couting the frequencey of cand1 and cand2.
        int c1 = 0, c2 = 0;
        for(int num: nums){
            if(num == cand1){
                c1++;
            } else if(num == cand2){
                c2++;
            }
        }
        // Verifying and seeding elements into the ans.
        vector<int> ans;
        if(c1 > (n/3)) ans.push_back(cand1);
        if(c2 > (n/3)) ans.push_back(cand2);
        return ans;
  
    }
};
