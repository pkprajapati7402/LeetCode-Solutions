/*
1941. Check if All Characters Have Equal Number of Occurrences
Solved
Easy
Topics
Companies
Hint
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

 

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length();
        vector<int> index(26,0);
        for(int i = 0; i < n; i++){
            index[s[i] - 'a']++;
        }
        // Method 1; Every comparision
        // for(int i = 0; i  < n - 1; i++){
        //     for(int j = 0; j < n; j++){
        //         if(index[s[i] - 'a'] != index[s[j] - 'a']){
        //             return false;
        //         }
        //     }
        // }
        // Method 2: logical one comparison.
        int t = index[s[0] - 'a'];
        for(int i = 1; i < n; i++){
            if(index[s[i] - 'a'] != t){
                return false;
            }
        }
        return true;
    }
};
