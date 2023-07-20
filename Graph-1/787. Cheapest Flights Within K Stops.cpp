#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(auto x: flights){
            adj[x[0]].push_back({x[1], x[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        // {stops, {node, dist}};
        q.push({0, {src, 0}});
        vector<int> ans(n, 1e9);
        ans[src] = 0;

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int stops = t.first;
            int node = t.second.first;
            int dist = t.second.second;

            if(stops > k){
                continue;
            }

            for(auto x: adj[node]){
                int adjnode = x.first;
                int edgeweight = x.second;

                if((dist + edgeweight < ans[adjnode]) && stops <= k){
                    ans[adjnode] = dist + edgeweight;
                    q.push({stops + 1, {adjnode, dist + edgeweight}});
                }
            }

        }

        if(ans[dst] == 1e9){
            return -1;
        }
        return ans[dst];
    }
};