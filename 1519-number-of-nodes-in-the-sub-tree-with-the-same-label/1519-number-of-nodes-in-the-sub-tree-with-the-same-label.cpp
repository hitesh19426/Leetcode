class Solution {
    vector<int> dfs(int src, int parent, vector<vector<int>>& graph, vector<int>& ans, string& labels){
        vector<int> count(26, 0);
        for(int v: graph[src]){
            if(v != parent){
                auto sub = dfs(v, src, graph, ans, labels);
                for(int i=0; i<26; i++)
                    count[i] += sub[i];
            }
        }
        ans[src] = ++count[labels[src]-'a'];
        return count;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n);
        dfs(0, -1, graph, ans, labels);
        return ans;
    }
};