class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    int find_next_state(int status, int count){
        if(status == 0)
            return count == 3;
        if(count == 2 || count == 3)
            return 1;
        return 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        int dx[] = {1,0,-1,0,1,1,-1,-1};
        int dy[] = {0,-1,0,1,1,-1,1,-1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    if(isvalid(i+dx[k], j+dy[k], m, n) && abs(board[i+dx[k]][j+dy[k]]) == 1)
                        count++;
                }

                int newState = find_next_state(board[i][j], count);
                if(newState != board[i][j]){
                    if(board[i][j] == 1)
                        board[i][j] = -1;
                    else
                        board[i][j] = -2;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] < 0){
                    if(board[i][j] == -1)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
            }
        }
    }
};