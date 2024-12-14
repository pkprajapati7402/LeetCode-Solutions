// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
       // return pow(x,0.5);
        int val = 0;
        for(long long i = 1; i <= 46342; i++){
            if(i * i == x){
                val = i;
                break;
            } 
            if(i * i > x){
                val = i - 1;
                break;
            }

        }
        return val;
    }
};
int main(){
    int x;
    cout << "Enter n: ";
    cin >> x;
    Solution myobj;
    cout << "Value: " << myobj.mySqrt(x) << endl;
    return 0;
}