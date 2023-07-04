#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int ans = INT_MAX;
        int index = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    index = mid;
                }
                index = mid;
                high = mid - 1;
            }
        }
        return index;
    }

    int search(vector<int>& nums, int target) {
        int index = findMin(nums);
        cout << index << endl;
        int left = search(nums, target, 0, index - 1);
        int right = search(nums, target, index, nums.size() - 1);



        if(left != -1){
            return left;
        }
        if(right != -1){
            return right;
        }
        return -1;
    }

    int search(vector<int> &nums, int target, int l, int r)
    {
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};