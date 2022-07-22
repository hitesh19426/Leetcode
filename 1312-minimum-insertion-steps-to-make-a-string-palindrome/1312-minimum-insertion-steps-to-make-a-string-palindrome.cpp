class Solution {
    int n;
    vector<vector<int>> dp;
    int helper(string &s, int low, int high){
        if(high <= low)
            return 0;
        if(dp[low][high] != -1)
            return dp[low][high];
        
        if(s[low] == s[high])
            return dp[low][high] = helper(s, low+1, high-1);
        return dp[low][high] = min(helper(s, low+1, high), helper(s, low, high-1)) + 1;
    }
public:
    int minInsertions(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return helper(s, 0, n-1);
    }
};