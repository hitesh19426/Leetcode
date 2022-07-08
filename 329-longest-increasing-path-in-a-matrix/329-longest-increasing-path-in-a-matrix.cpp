class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        int dir[] = {1,0,-1,0,1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    int newx = i+dir[k], newy = j+dir[k+1];
                    if(isvalid(newx, newy, m, n) && grid[newx][newy] < grid[i][j])
                        indegree[i][j]++;
                }
            }
        }
        
        queue<pair<int, int>> queue;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(indegree[i][j] == 0){
                    queue.push({i, j});
                }
            }
        }
        
        int level = 0;
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                auto [x, y] = queue.front();
                queue.pop();
                
                for(int k=0; k<4; k++){
                    int newx = x+dir[k], newy = y+dir[k+1];
                    if(isvalid(newx, newy, m, n) && grid[newx][newy] > grid[x][y]  && --indegree[newx][newy] == 0)
                        queue.push({newx, newy});
                }
            }
            level++;
        }
        
        return level;
    }
};