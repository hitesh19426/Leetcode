class Solution {
    const int WHITE = -1, GREY = 0, BLACK = 1;
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
    
    bool dfs(int src, int dest, vector<vector<int>>& graph){
        if(graph[src].empty())
            return (src == dest);
        for(int v: graph[src]){
            if(!dfs(v, dest, graph))
                return false;
        }
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<int> colors(n, WHITE);
        if(detectCycle(source, colors, graph))
            return false;
        
        return (dfs(source, destination, graph));
    }
};