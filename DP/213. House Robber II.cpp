#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums) {
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

    int rob(vector<int>& num1) {
        int n = num1.size();
        if(n == 1){
            return num1[0];
        }
        vector<int> num2;
        for(int i = 1; i < n; i++){
            num2.push_back(num1[i]);
        }
        num1.pop_back();
        return max(rob1(num1), rob1(num2));
    }
};