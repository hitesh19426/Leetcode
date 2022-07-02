class Node{
public:
    int x, y, dist;
    Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    
    bool operator<(const Node& other) const {
        if(dist != other.dist)
            return dist < other.dist;
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    int dijkstra(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        set<Node> minheap;
        
        minheap.insert(Node(0, 0, 0));
        dist[0][0] = 0;
        
        int dir[] = {1,0,-1,0,1}, res = 0;
        while(!minheap.empty()){
            auto [x, y, dis] = *minheap.begin();
            minheap.erase(minheap.begin());
            
            if(x == m-1 && y == n-1)
                return dis;
            
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy, m, n)){
                    int newdist = max(dist[x][y], abs(grid[x][y] - grid[newx][newy]));
                    if(dist[newx][newy] > newdist){
                        minheap.erase(Node(newx, newy, dist[newx][newy]));
                        dist[newx][newy] = newdist;
                        minheap.insert(Node(newx, newy, dist[newx][newy]));    
                    }
                }
            }
        }
                                                 
        return -1;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights);
    }
};