#include<bits/stdc++.h>

using namespace std;

// using stringstream
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string word;

        int ans;
        while(ss >> word){
            ans = word.length();
            break;
        }
        return ans;
    }
}; 

// reverse the string.
// skip the empty spaces at the front.
// count the length of the first word.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());

        // Covers all the spaces ahead of string.
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        int ans = 0;
        while(s[i] != ' ' && i < n){
            ans++;
            i++;
        }
        return ans;
    }
};