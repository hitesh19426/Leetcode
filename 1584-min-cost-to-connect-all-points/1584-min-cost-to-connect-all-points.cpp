class Solution {
    int distance(vector<vector<int>>& points, int i, int j){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), cost = 0;
        vector<int> dist(n, INT_MAX), vis(n, false);
        dist[0] = 0;
        
        for(int i=0; i<n; i++){
            int min_index = -1;
            for(int j=0; j<n; j++){
                if(!vis[j] && (min_index == -1 || dist[j] < dist[min_index]))
                    min_index = j;
            }
            
            vis[min_index] = true;
            cost += dist[min_index];
            for(int j=0; j<n; j++){
                if(!vis[j] && distance(points, min_index, j) < dist[j])
                    dist[j] = distance(points, min_index, j);
            }
        }
        
        return cost;
    }
};