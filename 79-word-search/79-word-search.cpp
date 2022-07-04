class Solution {
public:
    int rows, cols;
    
    bool dfs(int i, int j, vector<vector<char>>& board, int ind, string &word){
        if(i<0 || j<0 || i>=rows || j>=cols || board[i][j] != word[ind] )
            return false;
        
        if(ind == word.size()-1)
            return true;
        
        char current = board[i][j];
        board[i][j] = '*';
        
        bool possible = dfs(i-1, j, board, ind+1, word) || dfs(i+1, j, board, ind+1, word)                            || dfs(i, j-1, board, ind+1, word) || dfs(i, j+1, board, ind+1, word);
           
        board[i][j] = current;
        return possible;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs(i, j, board, 0, word))
                    return true;
            }
        }
        
        return false;
    }
};