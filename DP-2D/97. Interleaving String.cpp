#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        int k = i + j;

        if(i == n1 && j == n2){
            return true;
        }

        if(i == n1){
            return s2.substr(j) == s3.substr(k);
        }

        if(j == n2){
            return s1.substr(i) == s3.substr(k);
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        bool ans = false;
        if(s3[k] == s1[i]){
            ans = ans || helper(i + 1, j, s1, s2, s3, dp);
        }
        if(s3[k] == s2[j]){
            ans = ans || helper(i, j + 1, s1, s2, s3, dp);
        }
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        
        if(n1 + n2 != n3){
            return false;
        }
        return helper(0, 0, s1, s2, s3, dp);
    }
};