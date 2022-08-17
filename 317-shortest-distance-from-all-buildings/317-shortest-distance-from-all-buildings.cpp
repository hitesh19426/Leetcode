class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int buildings = 0, m = grid.size(), n = grid[0].size();
        int count[m][n], dist[m][n];
        memset(dist, 0, sizeof(dist));
        memset(count, 0, sizeof(count));
        int dir[] = {1, 0, -1, 0, 1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> queue;
                    bool vis[m][n];
                    memset(vis, 0, sizeof(vis));
                    queue.push({i, j});
                    
                    int currDistance = 0;
                    while(!queue.empty()){
                        int size = queue.size();
                        while(size--){
                            auto [x, y] = queue.front();
                            queue.pop();

                            for(int k=0; k<4; k++){
                                int newx = x+dir[k], newy = y+dir[k+1];
                                if(isvalid(newx, newy, m, n) && count[newx][newy] == buildings && !vis[newx][newy] && grid[newx][newy] == 0){
                                    queue.push({newx, newy});
                                    dist[newx][newy] += currDistance+1;
                                    vis[newx][newy] = true;
                                    count[newx][newy]++;
                                }
                            }
                        }
                        currDistance++;
                    }
                    
                    buildings++;
                }
            }
        }
        
        int min_dist = INT_MAX;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(count[i][j] == buildings && dist[i][j] < min_dist)
                    min_dist = dist[i][j];
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};
/*
TC(M, N) = O(M*N*(M*N))
SC(M, N) = O(M*N)
*/