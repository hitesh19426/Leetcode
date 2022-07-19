class Solution {
    int m, n;
    bool isvalid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> vis(m, vector<int>(n, false));
        
        pq.push({grid[0][0], 0});
        vis[0][0] = true;
        int res = grid[0][0], dir[] = {1,0,-1,0,1};
        
        while(!pq.empty()){
            auto [val, id] = pq.top();
            pq.pop();
                
            res = min(res, val);
            if(id == m*n-1)
                return res;
            
            int x = id/n, y = id%n;
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy) && !vis[newx][newy]){
                    pq.push({grid[newx][newy], newx*n + newy});
                    vis[newx][newy] = true;
                }
            }
        }
        return res;
    }
};