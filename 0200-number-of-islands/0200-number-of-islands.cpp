class Solution {
    int m, n;
    vector<int> dir{1,0,-1,0,1};
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';
        
        for(int k=0; k<4; k++){
            int newx = i+dir[k], newy = j+dir[k+1];
            if(newx>=0 && newy>=0 && newx<m && newy<n && grid[newx][newy] == '1')
                dfs(newx, newy, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};