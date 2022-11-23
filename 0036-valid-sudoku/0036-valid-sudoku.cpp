class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::bitset<9> row[9], col[9], box[3][3];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int ind = board[i][j] - '1';
                    if(row[i][ind] || col[j][ind] || box[i/3][j/3][ind])
                        return false;
                    
                    row[i][ind] = col[j][ind] = box[i/3][j/3][ind] = true;
                }
            }
        }
        
        return true;
    }
};