class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        int n = s.size();
        vector<int> prev(n+1, 0);
        
        for(int i=1; i<=n; i++){
            vector<int> curr(n+1, 0);
            for(int j=1; j<=n; j++){
                if(s[i-1] == s2[j-1])
                    curr[j] = prev[j-1] + 1;
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev.back();
    }
};