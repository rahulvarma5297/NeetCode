#include<bits/stdc++.h>
using namespace std;

// Union Find

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1, -1);

        for(auto x: edges){
            int u = x[0];
            int v = x[1];

            int parentU = find(parents, u);
            int parentV = find(parents, v);

            if(parentU == parentV){
                return x;
            }
            else{
                unionHelper(parents, parentU, parentV);
            }
        }

        return {};
    }

    int find(vector<int>& parents, int v){
        if(parents[v] < 0){
            return v;
        }
        return find(parents, parents[v]);
    }

    void unionHelper(vector<int>& parents, int a, int b){
        if(parents[a] > parents[b]){
            unionHelper(parents, b, a);
        }
        parents[b] = a;
    }

};