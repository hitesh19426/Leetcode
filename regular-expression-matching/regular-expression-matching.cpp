class Solution {
public:
    bool helper(vector<vector<int>>& dp, string& s, string& p, int i, int j){
        if(i<=0 && j<=0)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(j==0){
            dp[i][j] = true;
        }
        else if(i==0){
            dp[i][j] = false;
        }
        else if(s[i-1] == p[j-1]){
            dp[i][j] = helper(dp, s, p, i-1, j-1);
        }
        else if(p[j-1] == '.'){
            dp[i][j] = helper(dp, s, p, i-1, j-1);
        }
        else if(p[j-1] == '*'){
            dp[i][j] = helper(dp, s, p, i, j-2) || (helper(dp, s, p, i-1, j) && s[i-1] == p[j-2]) ;
        }
        else{
            dp[i][j] = false;
        }
        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        int m = s.size(),  n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        for(int i=1; i<=m; i++)
            dp[i][0] = false;
        for(int j=1; j<=n; j++)
            dp[0][j] = (p[j-1] == '*' ? dp[0][j-2] : false);
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){ // s[i-1] != [j-1] && [j-1] != '.' => p[j-1] = '*'
                    if(s[i-1] != p[j-2] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        dp[i][j] =  dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        
        return dp[m][n];
    }
};

/*
"aa"
".*.*"
"abbbbaaacc"
"ab*.*"
"abbbbaaaccaa"
"ab*a*cca*"
"abbbbaac"
"a*b*a*a"
*/