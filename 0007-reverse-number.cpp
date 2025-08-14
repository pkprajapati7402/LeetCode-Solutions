// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int rev = 0;
        while(x != 0){
            int digit = x % 10;
            rev = (rev * 10) + digit;
            x /= 10;
        }
        if((rev > pow(2,31) - 1) || (rev < -pow(2, 31))){
            return 0;
        } else{
            return rev;
        }
    }
};
int main(){
    int n;
    Solution myobj;
    cout << "Enter n: ";
    cin >> n;
    cout << "reverse: " << myobj.reverse(n) << endl;
    return 0;
}
