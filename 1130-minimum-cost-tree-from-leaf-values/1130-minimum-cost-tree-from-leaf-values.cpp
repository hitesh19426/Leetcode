class Solution {
    int max(vector<int> &arr, int i, int j){
        return *max_element(arr.begin()+i, arr.begin()+j+1);
    }
    
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for(int len = 1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                
                if(i == j){
                    dp[i][j] = 0;
                    continue;
                }
                
                for(int k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + max(arr, i, k)*max(arr, k+1, j) );
                }
                
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        
        return dp[0][n-1];
    }
};