class Solution {
    int dijkstra(int src, vector<vector<pair<int, int>>>& graph){
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> minheap;
        
        dist[src] = 0;
        minheap.insert({0, src});
        
        while(!minheap.empty()){
            auto [curr_dist, ver] = *minheap.begin();
            minheap.erase(minheap.begin());
            
            for(auto [v, len]: graph[ver]){
                if(curr_dist + len < dist[v]){
                    minheap.erase({dist[v], v});
                    dist[v] = curr_dist+len;
                    minheap.insert({dist[v], v});
                }
            }
        }
        
        int min_time = *max_element(dist.begin()+1, dist.end());
        return (min_time == INT_MAX ? -1 : min_time);
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
        for(auto &edge: times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        return dijkstra(k, graph);
    }
};