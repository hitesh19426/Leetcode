class Solution {
public:
    int dp[38];
    
    Solution(){
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for(int i=3; i<38; i++){
            // cout << dp[i-3] << " " << dp[i-2] << " " << dp[i-1] << endl;
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }
    
    int tribonacci(int n) {
        return dp[n];
    }
};