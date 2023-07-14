#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, string s, vector<int>& dp){
        int n = s.length();

        if(index >= n){
            return 1;
        }

        if(s[index] == '0'){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // single
        int one = helper(index + 1, s, dp);

        // double
        int two = 0;
        if(index < n - 1){
            int val = stoi(s.substr(index, 2));
            if(val <= 26){
                two = helper(index + 2, s, dp);
            }
        }

        return dp[index] = one + two;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return helper(0, s, dp);
    }
};