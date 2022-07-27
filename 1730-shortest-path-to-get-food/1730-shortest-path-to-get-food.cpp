class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> queue;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        bool done = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n ; j++){
                if(grid[i][j] == '*'){
                    queue.push({i, j});
                    dist[i][j] = 0;
                    done = true;
                    break;
                }
            }
            if(done)
                break;
        }
        
        int dir[] = {1,0,-1,0,1};
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();

            if(grid[x][y] == '#')
                return dist[x][y];

            for(int k=0; k<4; k++){
                int newx = x + dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy, m, n) && grid[newx][newy] != 'X' && dist[newx][newy] == INT_MAX){
                    dist[newx][newy] = dist[x][y]+1;
                    queue.push({newx, newy});
                }
            }
        }
        
        return -1;
    }
};