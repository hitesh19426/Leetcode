class Solution {
    bool reachable(int src, int dest, vector<bool>& vis, vector<vector<int>>& graph, vector<vector<int>>& dp){
        if(dp[src][dest] != -1)
            return dp[src][dest];
        vis[src] = true;
        if(src == dest)
            return dp[src][dest] = true;
        for(int v: graph[src]){
            if(!vis[v] && reachable(v, dest, vis, graph, dp))
                return dp[src][dest] = true;
        }
        return dp[src][dest] = false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for(auto &edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> ans;
        vector<vector<int>> dp(numCourses, vector<int>(numCourses, -1));
        for(auto &query: queries){
            vector<bool> vis(numCourses, false);
            ans.push_back(reachable(query[1], query[0], vis, graph, dp));
        }
        return ans;
    }
};