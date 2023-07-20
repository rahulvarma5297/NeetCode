#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for(auto x: times){
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v, wt});
        }
        vector<int> time(n + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({k, 0});
        time[k] = 0;

        int ans = 0;
        while(!q.empty()){
            int node = q.front().first;
            int wt1 = q.front().second;
            q.pop();

            for(auto x: adj[node]){
                if(time[x.first] > wt1 + x.second){
                    q.push({x.first, wt1 + x.second});
                    time[x.first] = wt1 + x.second;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            else{
                ans = max(ans, time[i]);
            }
        }
        return ans;
    }
};