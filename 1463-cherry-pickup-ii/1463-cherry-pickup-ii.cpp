class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dp[row][col][col];
        memset(dp, 0, sizeof(dp));
        
        for(int i=row-1; i>=0; i--){
            for(int r1=0; r1<col; r1++){
                for(int r2=r1; r2<col; r2++){
                    
                    int val = 0;
                    dp[i][r1][r2] = val + grid[i][r1] + (r1 == r2 ? 0 : grid[i][r2]);
                    if(i==row-1){
                        continue;
                    }
                    
                    for(int r1x=r1-1; r1x<=r1+1; r1x++){
                        for(int r2x=r2-1; r2x<=r2+1; r2x++){
                            if(r1x<0 || r2x<0 || r1x>=col || r2x>=col)
                                continue;
                            val = max(val, dp[i+1][r1x][r2x] );
                        }
                    }
                    
                    
                    dp[i][r1][r2] += val;
                }
            }
        }
        
        return dp[0][0][col-1];
    }
};