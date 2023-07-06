#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for(int i = 0; i < points.size();i++){
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({-dist, points[i]});
        }

        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};