class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        bool pal[n][n];
        
        for(int l=n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                if(l == r)
                    pal[l][r] = true;
                else if(l+1 == r)
                    pal[l][r] = (s[l] == s[r]);
                else
                    pal[l][r] = (s[l] == s[r] && pal[l+1][r-1]);
            }
        }
        
        for(int l=1; l<n-1; l++){
            for(int r=l; r<n-1; r++){
                if(pal[0][l-1] && pal[l][r] && pal[r+1][n-1])
                    return true;
            }
        }
        return false;
    }
};