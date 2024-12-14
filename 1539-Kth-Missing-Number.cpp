// 1539. Kth Missing Positive Number
// Easy
// Topics
// Companies
// Hint
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

 

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length
 

// Follow up:

// Could you solve this problem in less than O(n) complexity?


// Method 1: Using Bruteforce approach.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthPositive(int arr[], int k) {
        int n = sizeof(arr)/sizeof(arr[0]), a[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[j] == i+1){
                    break;
                } 
            }
            a[i] = i+ 1;
        }
        return arr[k-1];
    }
};
int main(){
    int arr[1000], k, n;
    cout << "Enter n: "; cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i <  n; i++){
        cin >> arr[i];
    }
    cout << "Enter K: "; cin >> k;
    Solution myobj;
    int val = myobj.findKthPositive(arr,k);
    cout << "Kth Missing number : " << val << endl;
    return 0;
}