class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        int area = 1;
        area += dfs(grid, i-1, j, row, col);
        area += dfs(grid, i+1, j, row, col);
        area += dfs(grid, i, j-1, row, col);
        area += dfs(grid, i, j+1, row, col);
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for(int i=0;  i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j, row, col));
                }
            }
        }      
        return ans;
    }
};