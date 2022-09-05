class Solution {
    vector<vector<int>> dp;
    int helper(string &s, string &t, int i, int j){
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = helper(s, t, i-1, j) + (s[i] == t[j] ? helper(s, t, i-1, j-1) : 0);
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        dp.assign(m, vector<int>(n, -1));
        return helper(s, t, m-1, n-1);
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