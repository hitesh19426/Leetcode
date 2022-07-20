class Solution {
    void dfs(int src, int parent, vector<vector<int>>& graph, vector<int>& ans, string& labels, int count[26]){
        for(int v: graph[src]){
            if(v != parent){
                int sub[26] = {};
                dfs(v, src, graph, ans, labels, sub);
                for(int i=0; i<26; i++)
                    count[i] += sub[i];
            }
        }
        ans[src] = ++count[labels[src]-'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n);
        int count[26] = {};
        dfs(0, -1, graph, ans, labels, count);
        return ans;
    }
};