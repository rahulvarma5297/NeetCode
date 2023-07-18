#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};

    void helper(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 0;

        for(int k = 0; k < 4; k++){
            int nrow = i + row[k];
            int ncol = j + col[k];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 1){
                helper(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 1));

        for(int i = 0; i < m; i++){
            if(vis[i][0] && board[i][0] == 'O') helper(i, 0, board, vis);
            if(vis[i][n-1] && board[i][n - 1] == 'O') helper(i, n - 1, board, vis);
        }

        for(int i = 0; i < n; i++){
            if(vis[0][i] && board[0][i] == 'O') helper(0, i, board, vis);
            if(vis[m-1][i] && board[m - 1][i] == 'O') helper(m - 1, i, board, vis);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};