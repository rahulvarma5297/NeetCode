#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int start, int target, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(target == 0){
            ans.push_back(temp);
        }

        for(int i = start; i < n; i++){
            if(i > start && nums[i] == nums[i - 1]){
                continue;
            }
            if(nums[i] <= target){
                temp.push_back(nums[i]);
                helper(i + 1, target - nums[i], temp, nums, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, target, temp, nums, ans);
        return ans;
    }
};