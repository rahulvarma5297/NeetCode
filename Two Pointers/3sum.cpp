#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int k = 0; k < n - 2; k++){

            // Unnecessary after this
            if(nums[k] > 0){
                break;
            }

            // same number repeat
            if(k > 0 && nums[k] == nums[k - 1]){
                continue;
            }

            int i = k + 1;
            int j = n - 1;

            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(sum < 0){
                    i++;
                }
                else if(sum > 0){
                    j--;
                }
                else{
                    ans.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1] ){
                        i++;
                    }
                    i++;
                    while(i < j && nums[j] == nums[j - 1]){
                        j--;
                    }
                    j--;
                }
            }
        }        
        return ans;
    }
};