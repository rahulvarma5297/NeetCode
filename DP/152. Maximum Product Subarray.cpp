#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, int& ans){
        int prod = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0){
                prod = 1;
            }
        }
    }
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        helper(nums, ans);
        reverse(nums.begin(), nums.end());
        helper(nums, ans);
        return ans;
    }
};