class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(auto& flight: flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        queue<pair<int, int>> queue;
        dist[src][0] = 0;
        queue.push({src, 0});
        
        int ans = INT_MAX;
        while(!queue.empty()){
            auto [node, stops] = queue.front();
            queue.pop();
            
            if(node == dst){
                ans = min(ans, dist[node][stops]);
            }
            
            for(auto [v, len]: graph[node]){
                if(stops <= k && dist[v][stops+1] > dist[node][stops] + len){
                    queue.push({v, stops+1});
                    dist[v][stops+1] = dist[node][stops] + len;
                }
            }
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};