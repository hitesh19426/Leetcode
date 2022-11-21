class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size(), dir[] = {1,0,-1,0,1};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, int>> queue;
        queue.push({entrance[0], entrance[1]});
        dist[entrance[0]][entrance[1]] = 0;
        
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();

            if(x != entrance[0] || y != entrance[1]){
                if(x == 0 || x == m-1 || y == 0 || y == n-1)
                    return dist[x][y];    
            }

            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(newx>=0 && newx<m && newy>=0 && newy<n && maze[newx][newy] != '+' && dist[newx][newy] == INT_MAX){
                    dist[newx][newy] = dist[x][y]+1;
                    queue.push({newx, newy});
                }
            }
        }
        
        return -1;
    }
};