// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45

#include <iostream>
#include <cmath>
using namespace std;

static int faster = [](){ std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); return 0;}();

class Solution {
public:
    int climbStairs(int n) {
        int rem = n / 2;
        int ways = pow(2, rem) + 1;
        return ways;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution myobj;
    cout << "Ways: " << myobj.climbStairs(n) << endl;
    return 0;
}
