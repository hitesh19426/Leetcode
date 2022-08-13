class Solution {
    void dfs(int src, vector<bool>& vis, vector<vector<int>>& graph){
        vis[src] = true;
        for(int v: graph[src]){
            if(!vis[v])
                dfs(v, vis, graph);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    graph[i].push_back(j);
            }
        }
        
        vector<bool> vis(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, graph);
                count++;
            }
        }
        
        return stones.size() - count;
    }
};