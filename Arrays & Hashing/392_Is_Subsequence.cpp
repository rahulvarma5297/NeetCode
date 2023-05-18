#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;

        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == m;
    }
};