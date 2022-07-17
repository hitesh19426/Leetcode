class Solution {
    
    
//     bool helper(string &s, string &p, int i, int j){
//         if(i == 0 && j == 0)
//             return dp[i][j] = true;
//         if(j == 0)
//             return dp[i][j] = false;
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(i == 0)
//             return dp[i][j] = (p[j-1] == '*' && helper(s, p, i, j-1));
//         if(s[i-1] == p[j-1] || p[j-1] == '?')
//             return dp[i][j] = helper(s, p, i-1, j-1);
//         if(p[j-1] == '*')
//             return dp[i][j] = (helper(s,p,i,j-1) || helper(s,p,i-1,j-1) || helper(s,p,i-1,j));
//         return dp[i][j] = false;
//     }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[0][0] = true;
        for(int j=1; j<=n; j++)
            dp[0][j] = (dp[0][j-1] && p[j-1] == '*');
        
        for(int i=1; i<=m; i++){
            dp[i][0] = false;
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
            }
        }
        

        return dp[m][n];
        // return helper(s, p, m, n);
    }
};