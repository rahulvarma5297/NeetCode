#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int start, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(start == n){
            ans.push_back(nums);
        }

        for(int i = start; i < n; i++){
            swap(nums[i], nums[start]);
            helper(start + 1, nums, ans);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};