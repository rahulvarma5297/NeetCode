#include<bits/stdc++.h>
using namespace std;

// Memoization: 
class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n <= 2){
            return dp[n] = n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        if(n == 1){
            return 1;
        }
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};