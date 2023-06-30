#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if (index >= n - 1){
            return 0;
        }

        if (dp[index] != -1){
            return dp[index];
        }

        int ans = 1e9;
        for (int i = 1; i <= nums[index]; i++){
            ans = min(ans, 1 + helper(index + i, nums, dp));
        }
        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9); // Initialize all values to a large number

        dp[n - 1] = 0; // Base case: last element requires 0 jumps

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }

        return dp[0];
    }
};
