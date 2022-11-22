class Solution {
public:
    int numSquares(int n) {
        int sq = 1;
        while(sq*sq <= n)
            sq++;
        sq--;
        
        vector<vector<int>> pos(sq+1, vector<int>(n+1, INT_MAX));
        pos[0][0] = 0;
        
        for(int i=1; i<=sq; i++){
            pos[i][0] = 0;
            for(int j=1; j<=n; j++){
                pos[i][j] = pos[i-1][j];
                if(j>=i*i)
                    pos[i][j] = min(pos[i][j], 1+pos[i][j-i*i]);
            }
        }
        
        return pos[sq][n];
    }
};