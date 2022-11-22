class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1; i*i<=n; i++){
            sq.push_back(i*i);
        }
        
        vector<vector<int>> pos(sq.size()+1, vector<int>(n+1, INT_MAX));
        pos[0][0] = 0;
        
        for(int i=1; i<=sq.size(); i++){
            pos[i][0] = 0;
            for(int j=1; j<=n; j++){
                pos[i][j] = pos[i-1][j];
                if(j>=sq[i-1] && pos[i][j-sq[i-1]] != INT_MAX)
                    pos[i][j] = min(pos[i][j], 1+pos[i][j-sq[i-1]]);
            }
        }
        
        return pos[sq.size()][n];
    }
};