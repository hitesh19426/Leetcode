class Solution {
    vector<vector<int>> graph, ans;
    vector<int> tin, low;
    
    void dfs(int src, int parent){
        static int timer = 0;
        tin[src] = low[src] = ++timer;
        for(int v: graph[src]){
            if(v == parent) continue;
            if(tin[v] != -1){  // v is visited
                low[src] = min(low[src], tin[v]);
            } else {
                dfs(v, src);
                low[src] = min(low[src], low[v]);
                if(low[v] > tin[src])
                    ans.push_back({v, src});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        tin.assign(n, -1);
        low.assign(n, -1);
        graph.assign(n, vector<int>());
        
        for(auto& conn: connections){
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        dfs(0, -1);
        return ans;
    }
};