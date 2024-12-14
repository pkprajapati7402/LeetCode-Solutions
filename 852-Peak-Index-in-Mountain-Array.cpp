// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


#include <algorithm>
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int mid, f = 0, l = arr.size() - 1, peak  = 0;
        while(f <= l){
            mid = f + (l - f)/2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid-1]){
                peak = mid;
                return mid;
            } else if((arr[mid] < arr[mid + 1]) || (arr[mid] > arr[mid - 1])){
                f = mid + 1;
            } else if((arr[mid] > arr[mid + 1]) || (arr[mid] < arr[mid - 1])){
                l = mid - 1;
            } 
        }
        return peak;
    }
};