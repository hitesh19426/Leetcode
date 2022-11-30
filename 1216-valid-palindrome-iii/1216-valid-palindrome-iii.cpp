class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int  n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 0;
            for(int j=i+1; j<n; j++){
                if(i == j-1){
                    dp[i][j] = (s[i] == s[j] ? 0 : 1);
                }else if(s[i] == s[j]){
                    dp[i][j] = min({dp[i+1][j-1], dp[i+1][j]+1, dp[i][j-1]+1});
                }else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[0][n-1] <= k;
    }
};