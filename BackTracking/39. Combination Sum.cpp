#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int start, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(start == nums.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        // take
        if(target >= nums[start]){
            temp.push_back(nums[start]);
            helper(start, target - nums[start], nums, temp, ans);
            temp.pop_back();
        }

        // not-take
        helper(start + 1, target, nums, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, target, candidates, temp, ans);
        return ans; 
    }
};