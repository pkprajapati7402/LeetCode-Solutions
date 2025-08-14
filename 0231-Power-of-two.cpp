// 231. Power of Two
// Solved
// Easy
// Topics
// Companies
// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 

// Constraints:

// -231 <= n <= 231 - 1
 

// Follow up: Could you solve it without loops/recursion?

// Method 1

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return 0;
        }
        while(n != 1){
            int rem = n % 2;
            if(rem == 1){
                return 0;
            }
            n /= 2;
        }
        return 1;
    }
};

// Method 2; My Logic.
#include <cmath>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i <= 100; i++){
            long long v = pow(2, i);
            if(v == n){
                 return 1;
            } else if(v > n){
                return 0;
            }
        }
        return 0;
    }
};
