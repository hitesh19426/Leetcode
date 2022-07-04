class Solution {
    const int GREY = 0, BLACK = -1, WHITE = 1;
    bool detectCycle(int src, vector<int>& colors, vector<vector<int>>& graph){
        colors[src] = GREY;
        for(int v: graph[src]){
            if(colors[v] == GREY)
                return true;
            if(colors[v] == WHITE && detectCycle(v, colors, graph))
                return true;
        }
        colors[src] = BLACK;
        return false;
    }
    
    vector<int> dfs(int src, string& colors, vector<vector<int>>& dp, vector<vector<int>>& graph){
        if(!dp[src].empty())
            return dp[src];
        
        vector<int> count(26, 0);
        for(int v: graph[src]){
            auto vec = dfs(v, colors, dp, graph);
            for(int i=0; i<26; i++)
                count[i] = max(count[i], vec[i]);
        }
        count[colors[src]-'a']++;
        return dp[src] = count;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> status(n, WHITE);
        vector<vector<int>> graph(n, vector<int>());
        
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0; i<n; i++){
            if(status[i] == WHITE && detectCycle(i, status, graph))
                return -1;
        }
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>());
        for(int i=0; i<n; i++){
            auto vec = dfs(i, colors, dp, graph);
            ans = max(ans, *max_element(vec.begin(), vec.end()));
        }
        return ans;
    }
};