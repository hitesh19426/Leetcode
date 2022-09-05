class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        long long dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for(int i=1; i<=m; i++){
            dp[i][0] = 1;
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%INT_MAX;
                }else{
                    dp[i][j] = dp[i-1][j]%INT_MAX;
                }
            }
        }
        
        return dp[m][n];
    }
};
/*
state: dp[i][j] = number of distinct subsequences of s[0..i] in t[0..j]
transition:
    if(s[i] == t[j])
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    else
        dp[i][j] = dp[i-1][j];
base case:
    dp[0][0] = 1, dp[0][j] = 0, dp[i][0] = 1;
final case:
    dp[m][n]
*/