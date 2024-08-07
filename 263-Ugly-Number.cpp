// 263. Ugly Number
// Easy
// Topics
// Companies
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

 

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3
// Example 2:

// Input: n = 1
// Output: true
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// Example 3:

// Input: n = 14
// Output: false
// Explanation: 14 is not ugly since it includes the prime factor 7.
 

// Constraints:

// -231 <= n <= 231 - 1

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){
            return 0;
        }
       while(n % 2 == 0) n /= 2;
       while(n % 3 == 0) n /= 3;
       while(n % 5 == 0) n /= 4;
       return n==1;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution obj;
    cout << "Result: " << obj.isUgly(n) << endl;
    return 0;
}