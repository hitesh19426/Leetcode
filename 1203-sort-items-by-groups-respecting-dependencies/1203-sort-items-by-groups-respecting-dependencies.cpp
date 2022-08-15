class Graph{
    unordered_map<int, int> indegree;
    unordered_map<int, unordered_set<int>> graph;
public:
    Graph() {}
    Graph(vector<int>& nodes){
        for(auto& x: nodes)
            graph[x] = unordered_set<int>();
    }
    void addEdge(int a, int b){
        if(graph[a].find(b) == graph[a].end())
            indegree[b]++;
        graph[a].insert(b);
    }
    vector<int> topoSort(){
        int rem = graph.size();
        queue<int> queue;
        for(auto &[key, value]: graph){
            if(indegree[key] == 0){
                queue.push(key);
            }
        }
        
        vector<int> ans;
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();
            rem--;
            ans.push_back(node);
            
            for(auto& v: graph[node]){
                if(--indegree[v] == 0){
                    queue.push(v);
                }
            }
        }
        
        return (rem == 0 ? ans : vector<int>());
    }
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int free_group = m;
        vector<int> allGroups;
        vector<vector<int>> groupsItems(m+n);
        for(int i=0; i<group.size(); i++){
            if(group[i] == -1)
                group[i] = free_group++;
            allGroups.push_back(group[i]);
            groupsItems[group[i]].push_back(i);
        }
        
        Graph groupsGraph(allGroups);
        vector<Graph> itemsGraph(m+n);
        for(int i=0; i<m+n; i++)
            itemsGraph[i] = Graph(groupsItems[i]);
        
        for(int i=0; i<n; i++){
            for(auto& before: beforeItems[i]){
                if(group[before] == group[i])
                    itemsGraph[group[i]].addEdge(before, i);
                else
                    groupsGraph.addEdge(group[before], group[i]);
            }
        }
        
        auto groupsOrder = groupsGraph.topoSort();
        if(groupsOrder.empty())
            return {};
        
        vector<int> ans;
        for(auto& grp: groupsOrder){
            auto order = itemsGraph[grp].topoSort();
            if(order.empty())
                return {};
            ans.insert(ans.end(), order.begin(), order.end());
        }
        return ans;
    }
};