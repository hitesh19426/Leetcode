class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0);
        
        pq.push({1, start});
        dist[start] = 1;
        
        while(!pq.empty()){
            const auto [prob, node] = pq.top();
            pq.pop();
            
            if(node == end)
                return prob;
            
            for(const auto& [v, p]: graph[node]){
                if(dist[v] < prob*p){
                    dist[v] = prob*p;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return 0;
    }
};