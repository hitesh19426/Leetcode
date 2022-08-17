class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e7));
        for(int i=0; i<n; i++)
            dist[i][i] = 0;
        for(auto &edge: edges){
            dist[edge[1]][edge[0]] = dist[edge[0]][edge[1]] = edge[2];
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int min_count = n+1, index = -1;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold)
                    count++;
            }
            if(count <= min_count)
                index = i, min_count = count;
        }
        return index;
    }
};