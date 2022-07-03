class Solution {
    double dijkstra(int start, int end, vector<vector<pair<int, double>>>& graph){
        int n = graph.size();
        vector<double> dist(n, 0);
        vector<bool> vis(n, false);
        queue<int> queue;
        
        queue.push(start);
        dist[start] = 1;
        
        while(!queue.empty()){
            auto ver = queue.front();
            queue.pop();
            
            for(auto [v, succ]: graph[ver]){
                double newprob = dist[ver]*succ;
                if(dist[v] < newprob){
                    dist[v] = newprob;
                    queue.push(v);
                }
            }
        }
         
        return dist[end];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        return dijkstra(start, end, graph);
    }
};