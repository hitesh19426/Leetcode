class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        int mod = 1e9+7;
        int dir[] = {1,0,-1,0,1};
        vector<vector<int>> prev(m, vector<int>(n, 0));
        
        for(int move=1; move<=maxMove; move++){
            vector<vector<int>> curr(m, vector<int>(n, 0));
            
            for(int x=0; x<m; x++){
                for(int y=0; y<n; y++){
                    long long count = 0;
                    
                    for(int k=0; k<4; k++){
                        int newx = x+dir[k], newy = y+dir[k+1];
                        if(isvalid(newx, newy, m, n))
                            count += prev[newx][newy];
                        else
                            count++;
                    }
                    
                    curr[x][y] = count%mod;
                }
            }
            
            prev = curr;
        }
        
        return prev[startRow][startCol];
    }
};