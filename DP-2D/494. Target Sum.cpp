#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    void helper(int start, vector<int>& nums, int target, int sum){
        if(start == nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }
        helper(start + 1, nums, target, sum + nums[start]);
        helper(start + 1, nums, target, sum - nums[start]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        helper(0, nums, target, 0);
        return count;
    }
};