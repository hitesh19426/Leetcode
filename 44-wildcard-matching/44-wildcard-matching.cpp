class Solution {
    int m, n;
    vector<vector<int>> dp;
    bool helper(string &s, string &p, int i, int j){
        if(i == 0 && j == 0)
            return dp[i][j] = true;
        if(j == 0)
            return dp[i][j] = false;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == 0)
            return dp[i][j] = (p[j-1] == '*' && helper(s, p, i, j-1));
        if(s[i-1] == p[j-1] || p[j-1] == '?')
            return dp[i][j] = helper(s, p, i-1, j-1);
        if(p[j-1] == '*')
            return dp[i][j] = (helper(s,p,i,j-1) || helper(s,p,i-1,j-1) || helper(s,p,i-1,j));
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        dp.assign(m+1, vector<int>(n+1, -1));
        return helper(s, p, m, n);
    }
};