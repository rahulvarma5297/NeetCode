#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp){
        // Base Case:
        if(index == 0){
            return amount % coins[0] == 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        // not-take
        int notake = helper(index - 1, amount, coins, dp);

        // take
        int take = 0;
        if(amount >= coins[index]){
            take = helper(index, amount - coins[index], coins, dp);
        }
        return dp[index][amount] = take + notake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return ans;
    }
};