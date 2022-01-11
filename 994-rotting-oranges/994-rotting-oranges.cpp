class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, ans = 0;
        
        queue<vector<int>> queue;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    queue.push({i, j, 0});
                    grid[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        vector<int> direc{1, 0, -1, 0, 1};
        while(!queue.empty()){
            int sz = queue.size();
            while(sz--){
                auto top = queue.front();
                queue.pop();
                
                for(int i=0; i<4; i++){
                    int x = top[0]+direc[i], y = top[1]+direc[i+1];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                        queue.push({x, y, top[2]+1});
                        grid[x][y] = 0;
                        ans = max(ans, top[2]+1);
                        fresh--;
                    }
                }
            }
        }
        
        return (fresh ? -1 : ans);
    }
};