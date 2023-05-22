#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<bool>> row(n, vector<bool>(n, false));
        vector<vector<bool>> col(n, vector<bool>(n, false));
        vector<vector<bool>> box(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(board[i][j] == '.'){
                    continue;
                }

                int index = board[i][j] - '0' - 1;
                int b = (i / 3) * 3 + j / 3;
                
                if(row[i][index] || col[j][index] || box[b][index]){
                    return false;
                }

                row[i][index] = true;
                col[j][index] = true;
                box[b][index] = true;

            }
        }
        return true ;
    }
};