class Solution {
    const int white = 1, grey = 0, black = -1;
    
    bool detectCycle(int src, vector<int>& colors, vector<vector<int>>& graph){
        colors[src] = grey;
        for(int v: graph[src]){
            if(colors[v] == grey)
                return true;
            if(colors[v] == white && detectCycle(v, colors, graph))
                return true;
        }
        colors[src] = black;
        return false;
    }
    
    void dfs(int src, vector<bool>& vis, vector<int>& ans, vector<vector<int>>& graph){
        vis[src] = true;
        for(int v: graph[src]){
            if(!vis[v])
                dfs(v, vis, ans, graph);
        }
        ans.push_back(src);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n, vector<int>());
        
        for(auto edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> colors(n, white);
        for(int i=0; i<n; i++){
            if(colors[i] == white && detectCycle(i, colors, graph))
                return {};
        }
        
        vector<int> ans;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, vis, ans, graph);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};