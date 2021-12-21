class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for(const int &x:arr)
            sum += x;
        
        if(sum&1)
            return false;
        
        sum /= 2;
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++)
                dp[i][j] = 0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1] == j){
                    dp[i][j] = true;
                }
                else if(j >= arr[i-1]){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};