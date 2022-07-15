class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        list<pair<int, int>> list;
        
        list.push_back({0, 0});
        dist[0][0] = 0;
        
        int move[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!list.empty()){
            auto [x, y] = list.front();
            list.pop_front();
            
            if(x == m-1 && y == n-1)
                return dist[x][y];
            
            for(int i=0; i<4; i++){
                int newx = x + move[i][0], newy = y + move[i][1], weight = (i+1 != grid[x][y]);
                if(isvalid(newx, newy, m, n) && dist[newx][newy] > dist[x][y] + weight){
                    dist[newx][newy] = dist[x][y] + weight;
                    if(weight == 0)
                        list.push_front({newx, newy});
                    else
                        list.push_back({newx, newy});   
                }
            }
        }
    
        return -1;
    }
};