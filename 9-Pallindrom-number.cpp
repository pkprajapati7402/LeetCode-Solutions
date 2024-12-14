// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1
 

// Follow up: Could you solve it without converting the integer to a string?

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
        long int temp = x;
        long int rev = 1;
        // reverse of number.
        while(temp != 0){
            int digit = temp % 10;
            rev += digit * 10;
            temp /= 10;
        }
        // checking for pallindrom.
        long int num = x;
        int flag = 1;
        while(num != 0){
            int digit1 = num % 10;
            int digit2 = rev % 10;
            if(digit1 != digit2){
                flag = 0;
                break;
            }
            rev /= 10;
            num /= 10;
        }
        if(flag){
            return true;
        } else{
            return false;
        }
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    isPalindrome(n);

}