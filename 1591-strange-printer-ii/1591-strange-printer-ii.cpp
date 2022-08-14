class Solution {
    const int WHITE = 1, BLACK = 0, GREY = -1;
    bool detectCycle(int src, vector<int>& state, vector<unordered_set<int>>& graph){
        state[src] = GREY;
        for(int v: graph[src]){
            if(state[v] == GREY)
                return true;
            if(state[v] == WHITE && detectCycle(v, state, graph))
                return true;
        }
        state[src] = BLACK;
        return false;
    }
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int colorsN = 60, m = targetGrid.size(), n = targetGrid[0].size();
        vector<unordered_set<int>> graph(colorsN+1);
        
        for(int color = 0; color<=colorsN; color++){
            int minx = INT_MAX, miny = INT_MAX, maxx = -1, maxy = -1;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(targetGrid[i][j] == color){
                        minx = min(minx, i);
                        maxx = max(maxx, i);
                        miny = min(miny, j);
                        maxy = max(maxy, j);
                    }
                }
            }
            
            if(minx == INT_MAX)
                continue;
            
            for(int i=minx; i<=maxx; i++){
                for(int j=miny; j<=maxy; j++){
                    if(targetGrid[i][j] != color){
                        graph[targetGrid[i][j]].insert(color);
                    }
                }
            }
        }
        
        vector<int> state(colorsN+1, WHITE);
        for(int i=0; i<=colorsN; i++){
            if(state[i] == WHITE && detectCycle(i, state, graph))
                return false;
        }
        return true;
    }
};