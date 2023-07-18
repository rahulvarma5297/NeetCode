#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int i = q.front().first.first;
                int j = q.front().first.second;
                int t = q.front().second;
                ans = max(ans, t);
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nrow = i + row[k];
                    int ncol = j + col[k];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, t + 1});
                        grid[nrow][ncol] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};