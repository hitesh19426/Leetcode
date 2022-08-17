class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        
        queue.push({start[0], start[1]});
        vis[start[0]][start[1]] = true;
        
        int move[][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for(int k=0; k<4; k++){
                int newx = x, newy = y;
                while(isvalid(newx, newy, m, n) && maze[newx][newy] == 0)
                    newx += move[k][0], newy += move[k][1];
                newx -= move[k][0], newy -= move[k][1];
                if(!vis[newx][newy]){
                    queue.push({newx, newy});
                    vis[newx][newy] = true;
                }
            }
        }
        
        return vis[dest[0]][dest[1]];
    }
};