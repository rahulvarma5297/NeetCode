#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};

    void helper(int i, int j, vector<vector<int>>& heights, set<pair<int, int>>& s){
        int m = heights.size();
        int n = heights[0].size();

        if(s.count({i, j})){
            return;
        }
        s.insert({i, j});

        for(int k = 0; k < 4; k++){
            int nrow = i + row[k];
            int ncol = j + col[k];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && heights[nrow][ncol] >= heights[i][j]){
                helper(nrow, ncol, heights, s);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        set<pair<int, int>> s1;
        set<pair<int, int>> s2;

        for(int i = 0; i < m; i++){
            helper(i, 0, heights, s1);
            helper(i, n - 1, heights, s2);
        }

        for(int i = 0; i < n; i++){
            helper(0, i, heights, s1);
            helper(m - 1, i, heights, s2);
        }
        vector<vector<int>> ans;
        for(auto x: s1){
            if(s2.count(x)){
                ans.push_back({x.first, x.second});
            }
        }
        return ans;
    }
};