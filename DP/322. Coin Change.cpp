#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp){
        // Base Case:
        if(index == 0){
            if(amount % coins[0]){
                return 1e5;
            }
            return amount / coins[0];
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        // not-take
        int notake = helper(index - 1, amount, coins, dp);

        // take
        int take = INT_MAX;
        if(amount >= coins[index]){
            take = 1 + helper(index, amount - coins[index], coins, dp);
        }
        return dp[index][amount] = min(take, notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
	    return ans >= 1e5 ? -1 : ans;
    }
};