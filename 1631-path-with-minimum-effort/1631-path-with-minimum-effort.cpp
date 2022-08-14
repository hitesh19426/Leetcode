class Node{
public:
    int x, y, dist;
    Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

class Solution {
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<Node> pq;
        
        dist[0][0] = 0;
        pq.push(Node(0, 0, 0));
        
        int dir[] = {1,0,-1,0,1};
        
        while(!pq.empty()){
            const auto [x, y, dis] = pq.top();
            pq.pop();
            
            if(x == m-1 && y == n-1)
                return dis;
            
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy, m, n)){
                    int w = max(dis, abs(heights[newx][newy] - heights[x][y]));
                    if(dist[newx][newy] > w){
                        dist[newx][newy] = w;
                        pq.push(Node(newx, newy, w));
                    }
                }
            }
        }
        
        return -1;
    }
};