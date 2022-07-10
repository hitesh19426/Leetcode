#include<bits/stdc++.h>
class Solution {
    bool solve(vector<vector<char>>& board, vector<pair<int, int>>& spaces, int pos, bool row[9][9], bool col[9][9], bool box[3][3][9]){
        if(pos == spaces.size())
            return true;
        
        int i = spaces[pos].first, j = spaces[pos].second;
        for(int digit=1; digit<=9; digit++){
            int ind = digit-1;
            if(row[i][ind] || col[j][ind] || box[i/3][j/3][ind])
                continue;
            
            board[i][j] = '0'+digit;
            row[i][ind] = col[j][ind] = box[i/3][j/3][ind] = true;
            if(solve(board, spaces, pos+1, row, col, box))
                return true;

            row[i][ind] = col[j][ind] = box[i/3][j/3][ind] = false;
        }
        
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {}, col[9][9] = {}, box[3][3][9] = {};
        vector<pair<int, int>> spaces;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    spaces.push_back({i, j});
                else{
                    int ind = board[i][j]-'1';
                    row[i][ind] = col[j][ind] = box[i/3][j/3][ind] = true;
                }
            }
        }
        
        solve(board, spaces, 0, row, col, box);
    }
};