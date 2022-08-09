class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge: edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> queue;
        vector<bool> vis(n, false);
        
        int rem = n;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1){
                queue.push(i);
            }
        }
        
        while(rem > 2){
            int size = queue.size();
            while(size--){
                auto node = queue.front();
                queue.pop();
                rem--;
                
                for(int v: graph[node]){
                    if(--indegree[v] == 1){
                        queue.push(v);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!queue.empty()){
            ans.push_back(queue.front());
            queue.pop();
        }
        return ans;
    }
};