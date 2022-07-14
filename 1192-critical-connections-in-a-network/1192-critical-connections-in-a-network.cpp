class Solution {
    vector<vector<int>> graph, ans;
    vector<bool> vis;
    vector<int> tin, low;
    int timer = 0;
    
    void dfs(int src, int parent){
        tin[src] = low[src] = ++timer;
        vis[src] = true;
        for(int v: graph[src]){
            if(v == parent) continue;
            if(vis[v]){  // v is visited
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
        vis.assign(n, false);
        graph.assign(n, vector<int>());
        
        for(auto& conn: connections){
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        dfs(0, -1);
        return ans;
    }
};