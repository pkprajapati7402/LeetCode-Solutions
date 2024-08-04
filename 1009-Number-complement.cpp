// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.



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
    int b = myobj.findComplement(n);
    cout << "complement: " << b << endl;
    return 0;
}



// Shortcut way.

class Solution {
public:
    int bitwiseComplement(int num) {

        int bin = 0, place = 1, a = num, k = 0;
        long int ans= 0;
        if(num == 0){
            return 1;
        }
        while(a != 0){
            int rem = a % 2;
            if(rem == 1){
                rem = 0;
            } else if(rem == 0){
                rem = 1;
            }
            ans += rem * pow(2,k);
            k++;

            a/=2;
        }
        return ans;
       
    }
};