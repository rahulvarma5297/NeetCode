#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> stk; 
        unordered_map<int, int> m;
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && stk.top() < nums2[i]){
                stk.pop();
            }
            m[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(m[x]);
        }
        return ans;
    }
};