/*
1952. Three Divisors
Solved
Easy
Topics
Companies
Hint
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

 

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.
 

Constraints:

1 <= n <= 104
*/


// Method 1: Brutforce approach.
// Directly diving and checking, complexity O(n)

class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        for(int i = 1; i <= (n); i++){
            if(n % i == 0){
                count++;
            }
        }
        if(count == 3){
            return 1;
        }
        return 0;
    }
};






// Method 2: Optimized approach. 
// using prime number, it's time complexity approx is O(sqrt(n))

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    bool isThree(int n) {
        int root = sqrt(n);
        if (root * root != n) {
            return false; 
        }
        return isPrime(root);
    }
};
