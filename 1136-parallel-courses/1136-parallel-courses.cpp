class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1, vector<int>());
        vector<int> indegree(n+1, 0);
        for(auto &relation: relations){
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        
        queue<int> queue;
        for(int i=1; i<=n; i++){
            if(indegree[i] == 0){
                queue.push(i);
            }
        }
        
        int level = 0, rem = n;
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                auto node = queue.front();
                queue.pop();
                rem--;
                
                for(int v: graph[node]){
                    if(--indegree[v] == 0){
                        queue.push(v);
                    }
                }
            }
            level++;
        }
        
        return (rem == 0 ? level : -1);
    }
};