#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x: nums){
            total += x;
        }

        int run = 0;
        for(int i = 0; i < n; i++){
            if(run == (total - nums[i] - run)){
                return i;
            }
            run += nums[i];
        }
        return -1;
    }
};