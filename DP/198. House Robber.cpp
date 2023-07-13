#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, vector<int>& nums){
        if(index < 0){
            return 0;
        }
        // take
        int take = nums[index] + helper(index - 2, nums);
        // not-take
        int notake = helper(index - 1, nums);
        return max(take, notake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            dp[i] = max((nums[i] + dp[i - 2]), dp[i - 1]);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};