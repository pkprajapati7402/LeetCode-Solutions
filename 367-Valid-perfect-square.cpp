/*
367. Valid Perfect Square
Easy
Topics
Companies
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 

Constraints:

1 <= num <= 231 - 1

*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        int f = 1, l = num;
        long long int mid; 
        if(num < 2){
            return 1;
        }     
        while(f <= l){
            mid = f + (l-f)/2;
            if(mid*mid == num){
                return 1;
            } else if(mid*mid < num){               
                f = mid + 1;
            } else{
                l = mid - 1;
            }
        }
        return 0;
    }
};