class Solution {
    int m, n;
    bool isvalid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int mid){    
        if(x == m-1 && y == n-1)
            return true;
        
        int dir[] = {1,0,-1,0,1};
        vis[x][y] = true;
        for(int k=0; k<4; k++){
            int newx = x+dir[k], newy = y+dir[k+1];
            if(isvalid(newx, newy) && grid[newx][newy] >= mid && !vis[newx][newy]){
                if(dfs(grid, vis, newx, newy, mid))
                    return true;
            }
        }
        
        return false;
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int low = INT_MAX, high = min(grid[0][0], grid[m-1][n-1]), ans = -1;
        for(auto &row: grid){
            for(int &x: row){
                low = min(low, x);
            }
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            if(grid[0][0] >= mid && dfs(grid, vis, 0, 0, mid))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};