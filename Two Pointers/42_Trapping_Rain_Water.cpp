#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int ans = 0;
        int leftMax = height[i];
        int rightMax = height[j];

        while(i < j){
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);

            if(height[i] <= height[j]){
                ans += (leftMax - height[i]);
                i++;
            }
            else{
                ans += (rightMax - height[j]);
                j--;
            }
        }
        return ans;
    }
};