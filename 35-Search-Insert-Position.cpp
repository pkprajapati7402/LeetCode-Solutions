// 35. Search Insert Position
// Easy
// Topics
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104



#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        int mid, f = 0, l = nums.size() - 1, val = nums.size();
        while(f <= l){
            mid = f + (l - f)/2;
            if(nums[mid] == target){
                val = mid;
                break;
            } else if(nums[mid] < target){
                f = mid + 1;
            } else if(nums[mid] > target){
                val = mid;
                l = mid - 1;
            }
        }
        return val;
    }
};
int main(){
    int n, a[1000];
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // target value.
    int tar;
    cout << "Enter target value: "; cin >> tar;
    Solution myobj;
    cout << "Index: " << myobj.searchInsert(a,tar);
    return 0;

}