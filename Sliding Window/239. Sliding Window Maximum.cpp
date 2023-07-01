#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for(int r = k; r < n; r++){
            pq.push({nums[r], r});
            int prev = r - k;

            while(pq.top().second <= prev){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};