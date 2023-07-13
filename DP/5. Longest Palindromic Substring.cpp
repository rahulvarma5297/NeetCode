#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int length = 0;

        for(int i = 0; i < n; i++){
            helper(s, i, i, start, length);
            helper(s, i, i + 1, start, length);
        }

        return s.substr(start, length);
    }

    void helper(string s, int i, int j, int& start, int& length){
        int n = s.length();

        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }

        if(j - i - 1 > length){
            start = i + 1;
            length = j - i - 1;
        }
    }
};