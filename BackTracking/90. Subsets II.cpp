#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int start, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        ans.push_back(temp);

        for(int i = start; i < n; i++){
            if(i > start && nums[i] == nums[i - 1]){
                continue;
            }
            temp.push_back(nums[i]);
            helper(i + 1, temp, nums, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, temp, nums, ans);
        return ans;
    }
};