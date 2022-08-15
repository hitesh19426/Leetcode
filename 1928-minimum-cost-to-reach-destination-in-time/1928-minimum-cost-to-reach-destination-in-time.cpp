class Solution {
    const int INF = 1e7;
    int dp[1001][1001];
    int helper(int src, int maxTime, int parent, int dest, vector<int>& cost, vector<vector<pair<int, int>>>& graph){
        if(maxTime < 0)
            return INF;
        if(src == dest)
            return cost[dest];
        if(dp[src][maxTime] != 0)
            return dp[src][maxTime];
        
        int minCost = INF;
        for(const auto &[v, t]: graph[src])
            minCost = min(minCost, cost[src] + helper(v, maxTime-t, src, dest, cost, graph));
        return dp[src][maxTime] = minCost;
    }
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        memset(dp, 0, sizeof(dp));
        vector<vector<pair<int, int>>> graph(n);
        for(auto &edge: edges){
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        auto ans = helper(0, maxTime, -1, n-1, passingFees, graph);
        return (ans == INF ? -1 : ans);
    }
};