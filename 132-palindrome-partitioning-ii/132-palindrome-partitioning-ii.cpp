class Solution {
    int helper(int ind, vector<vector<bool>>& is_palindrome, vector<int>& dp){
        if(ind <= 0)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int min_cut = INT_MAX;
        for(int j=1; j<=ind; j++){
            if(is_palindrome[j][ind]){
                min_cut = min(min_cut, 1+helper(j-1, is_palindrome, dp));
            }
        }
        // cout << ind << " " << min_cut << endl;
        if(is_palindrome[0][ind])
            min_cut = 0;
        
        return dp[ind] = min_cut;
    }
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
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++)
        //         cout << is_palindrome[i][j] << " ";
        //     cout << endl;
        // }
        
        vector<int> dp(n, -1);
        return helper(n-1, is_palindrome, dp);
        
        // for(int x: dp)
        //     cout << x << " ";
        // cout << endl;'
        
        
    }
};

/*

l...r => s[l] = s[r] && pal(l+1, r-1);


*/