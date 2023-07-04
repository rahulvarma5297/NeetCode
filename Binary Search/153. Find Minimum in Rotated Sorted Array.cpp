#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int ans = INT_MAX;
        while(low <= high){

            // if the array is sorted
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

// if array has duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int ans = INT_MAX;
        while(low <= high){

            // if the array is sorted
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            if(nums[low] < nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else if(nums[low] > nums[mid]){
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
            else{
                ans = min(ans, nums[low]);
                low++;
            }
        }
        return ans;
    }
};