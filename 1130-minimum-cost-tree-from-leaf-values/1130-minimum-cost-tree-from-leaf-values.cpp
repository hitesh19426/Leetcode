class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)), maximum(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            maximum[i][i] = arr[i];
            for(int j=i+1; j<n; j++)
                maximum[i][j] = ::max(maximum[i][j-1], arr[j]);
        }
        
        
        for(int len = 1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                
                if(i == j){
                    dp[i][j] = 0;
                    continue;
                }
                
                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+maximum[i][k]*maximum[k+1][j]);
                
            }
        }
        
        return dp[0][n-1];
    }
};