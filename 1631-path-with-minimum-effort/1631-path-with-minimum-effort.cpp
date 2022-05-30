class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int maxDiff, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if(!isvalid(x, y, m, n) || vis[x][y])
            return false;
        
        vis[x][y] = true;
        if(x == m-1 && y == n-1)
            return true;
        
        int dir[] = {1, 0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int newx = x + dir[k], newy = y + dir[k+1];
            if(isvalid(newx, newy, m, n) && abs(grid[newx][newy] - grid[x][y]) <= maxDiff){
                if(dfs(grid, vis, maxDiff, newx, newy))
                    return true;
            }
        }
        
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int low = 0, high = 1000000, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            if(dfs(heights, vis, mid, 0, 0))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        
        return ans;
    }
};