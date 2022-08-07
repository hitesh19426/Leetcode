class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[n+1][5], mod = 1e9+7;
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for(int i=2; i<=n; i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            dp[i][3] = dp[i-1][2]%mod;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3])%mod;
        }
        
        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4])%mod;
    }
};