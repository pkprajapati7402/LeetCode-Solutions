// 704. Binary Search
// Solved
// Easy
// Topics
// Companies
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid;
        while (l <= h) {
            mid = l + (h - l) / 2; 
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
};




// Extra code to reduce the time complexity. Use it before the class.
#include <algorithm>

int init = [] {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    for (string s; getline(cin, s); cout << '\n') {
        string t;
        getline(cin, t);
        int tar = stoi(t);

        for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
            bool _neg = 0;
            if (s[_i] == '-')
                ++_i, _neg = 1;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);
            if (_neg)
                v = -v;
            if (v == tar) {
                cout << i;
                goto next;
            }
            if (v > tar)
                break;
        }
        cout << -1;
    next:;
    }
    exit(0);
    return 0;
}();