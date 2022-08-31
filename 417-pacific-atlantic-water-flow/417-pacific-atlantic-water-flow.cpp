class Solution {
    int m, n;
    bool isvalid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    void bfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        queue<pair<int, int>> queue;
        
        for(int i=0; i<m; i++){
            queue.push({i, col});
            vis[i][col] = true;
        }
        for(int i=0; i<n; i++){
            queue.push({row, i});
            vis[row][i] = true;
        }
        int dir[] = {1,0,-1,0,1};
        
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy) && !vis[newx][newy] && grid[newx][newy] >= grid[x][y]){
                    queue.emplace(newx, newy);
                    vis[newx][newy] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> is_pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> is_atlantic_reachable(m, vector<bool>(n, false));
        
        bfs(0, 0, is_pacific_reachable, heights);
        bfs(m-1, n-1, is_atlantic_reachable, heights);
        
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(is_pacific_reachable[i][j] && is_atlantic_reachable[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};