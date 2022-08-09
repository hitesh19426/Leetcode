class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string res = s + ":" + rev;
        
        vector<int> lps(res.size());
        lps[0] = 0;
        int i = 1, j = 0;
        while(i<res.size()){
            if(res[i] == res[j]){
                lps[i] = j+1;
                i++, j++;
            }
            else if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0, i++;
            }
        }
        
        int ins = s.size() - lps.back();
        for(int i=ins-1; i>=0; i--)
            rev += rev[i];
        return rev;
    }
};