class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),  n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        queue<vector<int>> queue;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    queue.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }
        
        vector<int> direc{1, 0, -1, 0, 1};
        
        while(not queue.empty()){
            int size = queue.size();
            while(size--){
                auto front = queue.front();
                queue.pop();
                
                for(int i=0; i<4; i++){
                    int x = front[0]+direc[i], y = front[1]+direc[i+1];
                    if(x>=0 && y>=0 && x<m && y<n && dist[x][y] == -1){
                        dist[x][y] = dist[front[0]][front[1]]+1;
                        queue.push({x, y, dist[x][y]});
                    }
                }
            }    
        }
        
        return dist;
    }
};