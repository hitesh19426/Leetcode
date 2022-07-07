class Solution {
    vector<vector<int>> dp;
    bool helper(string &s1, int i, string& s2, int j, string res, string s3, int k){
        if(i == s1.size() && j == s2.size())
            return (res == s3);
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = false;
        if(i<s1.size() && s1[i] == s3[k])
            ans |= helper(s1, i+1, s2, j, res+s1[i], s3, k+1);

        if(j<s2.size() && s2[j] == s3[k])
            ans |= helper(s1, i, s2, j+1, res+s2[j], s3, k+1);

        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
        return helper(s1, 0, s2, 0, "", s3, 0);
    }
};