// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

// Example 1:

// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0
 

// Constraints:

// 0 <= num <= 231 - 1
 

// Follow up: Could you do it without any loop/recursion in O(1) runtime?


// Method1:
#include <iostream>
using namespace std;

static int faster = [](){ std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int addDigits(int num) {
        int sum = 0, sum2 = 0, sum3 = 0;
        
        while(num != 0){
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        while(sum != 0){
            int digit = sum % 10;
            sum2 += digit;
            sum /= 10;
        }
        while(sum2 != 0){
            int digit = sum2 % 10;
            sum3 += digit;
            sum2 /= 10;
        }
        return sum3;
    }
};

// Method 2:
#include <iostream>
using namespace std;

class Solution2 {
public:
    int addDigits(int num) {
       
        while(num >= 9){
            int rem, ans = 0;
            while( num != 0){
                rem = num % 10;
                ans += rem;
                num /= 10;
            }
            num = ans;
        }
        return num;
    }
};
int main(){
    int n;
    cout << "Enter N: ";
    cin >> n;
    Solution2 myobj;
    cout << "Ans: " << myobj.addDigits(n) << endl;
    return 0;
}