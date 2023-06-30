#include <bits/stdc++.h>
using namespace std;

// Memoization:
bool helper(int index, vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    if (index >= n - 1)
    {
        return true;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    bool ans = false;
    for (int i = 1; i <= nums[index]; i++)
    {
        ans = ans || helper(index + i, nums, dp);
    }
    return dp[index] = ans;
}

// Tabulation:
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[n - 1] = true;

    for (int i = n - 2; i >= 0; i--)
    {
        bool ans = false;
        for (int j = 1; j <= nums[i]; j++)
        {
            if (i + j < n)
            {
                ans = ans || dp[i + j];
            }
        }
        dp[i] = ans;
    }
    return dp[0];
}

// Greedy:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i > ans){
                return false;
            }
            ans = max(ans, i + nums[i]);
        }
        return ans >= n - 1;
    }
};