#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 1;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        while(i < n){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};