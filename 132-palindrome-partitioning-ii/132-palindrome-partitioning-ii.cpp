class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        for(int l=n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                if(l == r)
                    is_palindrome[l][r] = true;
                else if(l+1 == r)
                    is_palindrome[l][r] = (s[l] == s[r]);
                else
                    is_palindrome[l][r] = (s[l] == s[r] && is_palindrome[l+1][r-1]);
            }
        }
        
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int ind=n-2; ind>=0; ind--){
            if(is_palindrome[ind][n-1]){
                dp[ind] = 0;
            }
            else{
                for(int j=ind; j<n-1; j++){
                    if(is_palindrome[ind][j])
                        dp[ind] = min(dp[ind], 1+dp[j+1]);
                }
            }
        }
        
        return dp[0];
        // return helper(n-1, is_palindrome, dp);
    }
};
/*
T(n) = n*n + n*n
S(n) = n*n + n
*/

/*
l...r => s[l] = s[r] && pal(l+1, r-1);
*/