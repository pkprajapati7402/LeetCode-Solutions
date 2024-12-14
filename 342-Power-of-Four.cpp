// 342. Power of Four
// Solved
// Easy
// Topics
// Companies
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
 

// Constraints:

// -231 <= n <= 231 - 1
 

// Follow up: Could you solve it without loops/recursion?


// Method 1: Recursion
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        // using recursion not loops.
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            return 1;
        } 
        if(n%4 != 0){
            return 0;
        }
        return isPowerOfFour(n/4);
    }
};

// Method 2: Old method

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i = 0; i <= 100; i++){
            long long v = pow(4, i);
            if(v == n){
                 return 1;
            } else if(v > n){
                return 0;
            }
        }
        return 0;
    }
};