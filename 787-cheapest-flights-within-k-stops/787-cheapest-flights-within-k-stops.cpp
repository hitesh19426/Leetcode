class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& flight: flights){
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        
        
        vector<vector<int>> dist(n, vector<int>(k+3, INT_MAX));
        queue<int> queue;
        
        queue.push(src);
        dist[src][0] = 0;
        
        int ans = INT_MAX;
        for(int i=0; i<k+2; i++){
            int size = queue.size();
            while(size--){
                auto node = queue.front();
                queue.pop();
                
                if(node == dst)
                    ans = min(ans, dist[node][i]);
                
                for(auto [v, w]: graph[node]){
                    if(dist[v][i+1] > dist[node][i] + w){
                        dist[v][i+1] = dist[node][i] + w;
                        queue.push(v);
                    }
                }
            }
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};