class Point{
public:
    int x, y, val;
    Point(int x, int y, int val) : x(x), y(y), val(val) {}
    
    bool operator<(const Point &other) const {
        return val > other.val;
    }
};

class Solution {
    bool isvalid(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        priority_queue<Point, vector<Point>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push(Point(0, 0, grid[0][0]));
        vis[0][0] = true;
        
        int dir[] = {1,0,-1,0,1};
        while(!pq.empty()){
            auto [x, y, val] = pq.top();
            pq.pop();
            
            res = max(res, val);
            if(x == n-1 && y == n-1)
                return res;
            
            for(int k=0; k<4; k++){
                int newx = x+dir[k], newy = y+dir[k+1];
                if(isvalid(newx, newy, n) && !vis[newx][newy]){
                    pq.push(Point(newx, newy, grid[newx][newy]));
                    vis[newx][newy] = true;
                }
            }
        }
        
        return res;
    }
};