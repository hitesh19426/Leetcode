class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(5, INT_MAX)));
        list<vector<int>> list;
        
        list.push_back({0, 0, grid[0][0]});
        dist[0][0][grid[0][0]] = 0;
        
        int move[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!list.empty()){
            auto state = list.front();
            list.pop_front();
            
            int x = state[0], y = state[1], dir = state[2];
            int newx = x + move[dir-1][0], newy = y + move[dir-1][1];
            
            if(x == m-1 && y == n-1)
                return dist[x][y][dir];
            
            if(isvalid(newx, newy, m, n) && dist[newx][newy][grid[newx][newy]] > dist[x][y][dir]){
                dist[newx][newy][grid[newx][newy]] = dist[x][y][dir];
                list.push_front({newx, newy, grid[newx][newy]});
            }
            for(int i=1; i<=4; i++){
                if(i != dir && dist[x][y][i] > dist[x][y][dir]+1){
                    dist[x][y][i] = dist[x][y][dir]+1;
                    list.push_back({x, y, i});
                }
            }
        }
    
        return -1;
    }
};