class Solution {
    struct comparator{
        bool operator()(pair<long long, int>& a, pair<long long, int>& b){
            return a.first > b.first;
        }
    };
    
    vector<long long> dijkstra(int src, vector<vector<pair<int, int>>>& graph){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, comparator> pq;
        vector<long long> dist(graph.size(), LLONG_MAX);
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto& [v, w]: graph[node]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({d+w, v});
                }
            }
        }
        return dist;
    }
    
    long long helper(int node, int start, vector<int>& dp, vector<long long>& dist, vector<vector<pair<int, int>>>& graph){
        if(node == start)
            return 1;
        if(dp[node] != -1)
            return dp[node];
        
        long long count = 0, mod = 1e9+7;
        for(auto &[v, w]: graph[node]){
            if(dist[v] > dist[node])
                count += helper(v, start, dp, dist, graph);
        }
        return dp[node] = count%mod;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& edge: edges){
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        auto dist = dijkstra(n, graph);
        vector<int> dp(n+1, -1);
        helper(n, 1, dp, dist, graph);        
        return dp[n];
    }
};
/*
TC(N) = ElogN + E + N
SC(N) = O(N + E)
*/