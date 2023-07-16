#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 1;

        for(int k = 0; k < 4; k++){
            int nrow = i + row[k];
            int ncol = j + col[k];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && matrix[nrow][ncol] > matrix[i][j]){
                ans = max(ans, 1 + helper(nrow, ncol, matrix, dp));
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, helper(i, j, matrix, dp));
            }
        }
        return ans;
    }
};