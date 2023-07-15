#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int start, int target, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(start == n){
            if(target == 0){
                return true;
            }
            return false;
        }

        if(dp[start][target] != -1){
            return dp[start][target];
        }

        bool ans = false;
        // take
        if(nums[start] <= target){
            ans = ans || helper(start + 1, target - nums[start], nums, dp);
        }

        // notake
        ans = ans || helper(start + 1, target, nums, dp);

        return dp[start][target] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        if(sum % 2){
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(sum  + 1, -1));
        return helper(0, sum / 2, nums, dp);
    }
};