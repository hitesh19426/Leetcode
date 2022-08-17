class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int buildings = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> count(m, vector<int>(n)), dist(m, vector<int>(n));
        vector<int> dir{1, 0, -1, 0, 1};
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    buildings++;
                    queue<pair<int, int>> queue;
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    queue.push({i, j});
                    vis[i][j] = true;
                    
                    int currDistance = 0;
                    while(!queue.empty()){
                        int size = queue.size();
                        while(size--){
                            auto [x, y] = queue.front();
                            queue.pop();

                            for(int k=0; k<4; k++){
                                int newx = x+dir[k], newy = y+dir[k+1];
                                if(isvalid(newx, newy, m, n) && !vis[newx][newy] && grid[newx][newy] == 0){
                                    queue.push({newx, newy});
                                    dist[newx][newy] += currDistance+1;
                                    vis[newx][newy] = true;
                                    count[newx][newy]++;
                                }
                            }
                        }
                        currDistance++;
                    }
                    
                    // for(int i=0; i<m; i++){
                    //     for(int j=0; j<n; j++)
                    //         cout << dist[i][j] << " ";
                    //     cout << endl;
                    // }
                    // cout << endl;
                }
            }
        }
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++)
        //         cout << count[i][j] << " ";
        //     cout << endl;
        // }
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++)
        //         cout << dist[i][j] << " ";
        //     cout << endl;
        // }
        
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