// 476. Number Complement
// Easy
// Topics
// Companies
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

 

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.


#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // Number to binary with complement.
        int bin = 0, place = 1, a = num;
        while(a != 0){
            int rem = a % 2;
            if(rem == 1){
                rem = 0;
            } else if(rem == 0){
                rem = 1;
            }
            bin += rem * place;
            place *= 10;
            a/=2;
        }
        // Binary to decimal.
        int dec = 0, k = 0;
        while(bin != 0){
            int rem = bin % 10;
            dec += rem * pow(2,k);
            k++;
            bin /= 10;
        }
        return dec;

    }
};
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution myobj;
    cout << "complement: " << myobj.findComplement(n) << endl;
    return 0;
}



// Using Bit method to overcome the issue of size overflow.
class Solution {
public:
    int findComplement(int num) {
         int complement = 0;
        int bit_position = 1;
        while (num != 0) {
            if ((num & 1) == 0) {
                complement |= bit_position;
            }
            num >>= 1;
            bit_position <<= 1;
        }
        return complement;
    }
};

