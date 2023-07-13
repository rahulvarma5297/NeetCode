#include<bits/stdc++.h>
using namespace std;

// Memoization:
class Solution {
public:
    int helper(int index, vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int next1 = helper(index + 1, cost, dp);
        int next2 = helper(index + 2, cost, dp);
        return dp[index] = cost[index] + min(next1, next2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        int first = helper(0, cost, dp);
        int second = helper(1, cost, dp);
        return min(first, second);
    }
};