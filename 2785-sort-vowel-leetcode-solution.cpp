/*
2785. Sort Vowels in a String
Medium
Topics
Companies
Hint
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        // find and count vowels.
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                lower[s[i] - 'a']++;
            } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                upper[s[i] - 'A']++;
            }
        }
        // Make string for sorted vowels.
        vector<char> vowels;
        for(int  i = 0; i < 26; i++){
            if(upper[i] > 0){
                for(int j = 0; j < upper[i]; j++){
                    vowels.push_back('A' + i);
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(lower[i] > 0){
                for(int j = 0; j < lower[i]; j++){
                    vowels.push_back('a' + i);
                }
            }
        }
        // vector<char> ans;
        // Substitution.
        int vindex = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vowels[vindex];
                vindex++;
            } else{
                // ans += s[i];
                s[i] = s[i];
            }
        }
        return s;
    }
};


int main(){
    string x;
    cout << "Enter a string: "; cin >> x;
    Solution obj;
    cout << "sorted string: " << obj.sortVowels(x) << endl;
    return 0;
}
