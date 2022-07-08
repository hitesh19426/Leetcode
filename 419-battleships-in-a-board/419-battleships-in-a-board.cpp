class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X'){
                    bool inc = true;
                    if(i>0 && board[i-1][j] == 'X')
                        inc = false;
                    if(j>0 && board[i][j-1] == 'X')
                        inc = false;
                    count += inc;
                }
            }
        }
        
        return count;
    }
};