#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(index >= n){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        // not-buy
        int notbuy = helper(index + 1, buy, prices, dp);

        // buy
        int buyval = 0;
        if(buy){
            buyval = -prices[index] + helper(index + 1, 0, prices, dp);
        }else{
            buyval = prices[index] + helper(index + 2, 1, prices, dp);
        }
        return dp[index][buy] = max(notbuy, buyval);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};