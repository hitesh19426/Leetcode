class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    struct Node{
        int dist, x, y;
        Node(int dist, int x, int y) : x(x), y(y), dist(dist) {}
        bool operator<(const Node& other) const {
            return dist > other.dist;
        }
    };
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<Node> pq;
        
        pq.push(Node(0, start[0], start[1]));
        dist[start[0]][start[1]] = 0;
        
        int move[][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        
        while(!pq.empty()){
            auto [d, x, y] = pq.top();
            pq.pop();
            
            for(int k=0; k<4; k++){
                int newx = x, newy = y, w = 0;
                while(isvalid(newx, newy, m, n) && maze[newx][newy] == 0)
                    newx += move[k][0], newy += move[k][1], w++;
                newx -= move[k][0], newy -= move[k][1], w--;
                if(dist[newx][newy] > d + w){
                    dist[newx][newy] = d + w;
                    pq.push(Node(d+w, newx, newy));
                }
            }
        }
        
        return (dist[dest[0]][dest[1]] != INT_MAX ? dist[dest[0]][dest[1]] : -1);
    }
};