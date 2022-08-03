class Solution {
    void bfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis){
        int m = grid.size(), n = grid[0].size(), ans = 0;
        queue<pair<int, int>> queue;
        
        for(int i=0; i<m; i++){
            queue.push({i, col});
            vis[i][col] = true;
        }
        for(int j=0; j<n; j++){
            queue.push({row, j});
            vis[row][j] = true;
        }

        int dir[] = {1,0,-1,0,1};
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(newx>=0 && newy>=0 && newx<m && newy<n && grid[x][y] <= grid[newx][newy] && !vis[newx][newy]){
                    vis[newx][newy] = true;
                    queue.push({newx, newy});
                }
            }
        }
        
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> is_pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> is_atlantic_reachable(m, vector<bool>(n, false));
        
        bfs(grid, 0, 0, is_pacific_reachable);
        bfs(grid, m-1, n-1, is_atlantic_reachable);
        
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(is_pacific_reachable[i][j] && is_atlantic_reachable[i][j])
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};