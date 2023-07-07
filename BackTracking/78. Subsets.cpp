#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int start, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(start == nums.size()){
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[start]);
        helper(start + 1, temp, nums, ans);
        // back-track
        temp.pop_back();

        // not-take
        helper(start + 1, temp, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, temp, nums, ans);
        return ans;
    }
};