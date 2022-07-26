class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int ball = 0; ball < n; ball++){
            int x = 0, y = ball, passed = true;
            while(x<m && y>=0 && y<n){
                if(y+grid[x][y] == n || y+grid[x][y] == -1 || grid[x][y+grid[x][y]] != grid[x][y]){
                    passed = false;
                    break;
                }else{
                    int inc = grid[x][y];
                    x += 1, y += inc;
                }
            }
            if(passed)
                ans[ball] = y;
        }
        
        return ans;
    }
};