class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),  n = mat[0].size();
        vector<vector<int>> dp(m+2, vector<int>(n+2, 1e6));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(mat[i-1][j-1] == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+1);
                }
            }
        }
        
        for(int i=m; i>0; i--){
            for(int j=n; j>0; j--){
                if(mat[i-1][j-1] != 0){
                    dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])+1);
                }
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                ans[i-1][j-1] = dp[i][j];
            }
        }
        
        return ans;
    }
};