#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};

    int bfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = 0;

        int ans = 1;

        for(int k = 0; k < 4; k++){
            int nrow = i + row[k];
            int ncol = j + col[k];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                ans += bfs(nrow, ncol, grid);
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int val = bfs(i, j, grid);
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }
};