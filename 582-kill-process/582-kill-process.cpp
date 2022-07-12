class Solution {
    void dfs(int src, unordered_map<int, vector<int>>& graph, vector<int>& ans){
        ans.push_back(src);
        for(int v: graph[src])
            dfs(v, graph, ans);
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<pid.size(); i++){
            graph[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        dfs(kill, graph, ans);
        return ans;
    }
};