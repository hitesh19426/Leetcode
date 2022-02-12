class Solution {
public:
    int n;
        
    int topdown(vector<vector<int>>& dp, vector<vector<int>> &maximum, vector<int>& arr, int i, int j){
        if(i == j)
            return 0;
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        int temp = INT_MAX;
        for(int k=i; k<j; k++)
                temp = min(temp, topdown(dp, maximum, arr, i, k) + topdown(dp, maximum, arr, k+1, j) + maximum[i][k]*maximum[k+1][j]);
        
        return (dp[i][j] = temp);
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)), maximum(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            maximum[i][i] = arr[i];
            for(int j=i+1; j<n; j++)
                maximum[i][j] = ::max(maximum[i][j-1], arr[j]);
        }
        
        return topdown(dp, maximum, arr, 0, n-1);
    }
};