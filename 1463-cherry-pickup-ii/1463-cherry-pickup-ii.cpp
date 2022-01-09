class Solution {
public:
    int max(int a, int b){
        return (a>b ? a : b);
    }
    
    void print(vector<vector<vector<int>>>& matrix){
        int row = matrix.size(), col = matrix[0].size();
        for(int i=row-1; i>=0; i--){
            cout << "row = " << i << endl;
            for(int r1=0; r1<col; r1++){
                for(int r2=r1; r2<col; r2++){
                    cout << "col1, col2, val = " << r1 << " " << r2 << " " << matrix[i][r1][r2] << endl;
                }
            }
            cout << endl;
        }
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));
        
        for(int i=row-1; i>=0; i--){
            for(int r1=0; r1<col; r1++){
                for(int r2=r1; r2<col; r2++){
                    
                    if(i==row-1){
                        dp[i][r1][r2] = grid[i][r1] + (r1 == r2 ? 0 : grid[i][r2]);
                        continue;
                    }
                    
                    int val = 0; 
                    for(int r1x:{-1, 0, 1}){
                        for(int r2x:{-1, 0, 1}){
                            if(r1+r1x<0 || r2+r2x<0 || r1+r1x>=col || r2+r2x>=col)
                                continue;
                            if(r2+r2x<r1+r1x)
                                continue;
                            val = max(val, dp[i+1][r1+r1x][r2+r2x] );
                        }
                    }
                    
                    if(r1 == r2){    
                        dp[i][r1][r2] = val + grid[i][r1];
                    }
                    else{
                        dp[i][r1][r2] = val + grid[i][r1] + grid[i][r2];
                    }
                    
                }
            }
        }
        
        // print(dp);
        
        return dp[0][0][col-1];
    }
};