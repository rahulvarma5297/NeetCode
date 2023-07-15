#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int start, string& s, unordered_map<string, int>& m, vector<int>& len, vector<int>& dp){
        int n = s.length();
        if(start == n){
            return true;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        bool ans = false;
        for(int i = 0; i < len.size(); i++){
            if(start + len[i] <= n && m[s.substr(start, len[i])]){
                ans = ans || helper(start + len[i], s, m, len, dp);
            }
        }
        return dp[start] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> m;
        vector<int> len;
        for(auto x: wordDict){
            len.push_back(x.length());
            m[x]++;
        }
        vector<int> dp(n, -1);
        return helper(0, s, m, len, dp);
    }
};