class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int dp[m+1][n+1];
        pair<int, int> parent[m+1][n+1];
        
        dp[0][0] = 0;
        for(int i=1; i<=m; i++){
            parent[i][0] = {i-1, 0};
            dp[i][0] = i;
        }
        for(int j=1; j<=n; j++){
            parent[0][j] = {0, j-1};
            dp[0][j] = j;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    parent[i][j] = {i-1, j-1};
                }
                else if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = dp[i-1][j]+1;
                    parent[i][j] = {i-1, j};
                }
                else{
                    dp[i][j] = dp[i][j-1] + 1;
                    parent[i][j] = {i, j-1};
                }
            }
        }
        
        int x = m, y = n;
        string ans = "";
        while(x != 0 || y != 0){
            auto &p = parent[x][y];
            if(p.first == x)
                ans += str2[y-1];        
            else
                ans += str1[x-1];
            x = p.first, y = p.second;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
"bbbaaaba"
"bbababbb"
*/