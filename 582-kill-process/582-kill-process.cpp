class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<pid.size(); i++){
            graph[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        queue<int> queue;
        queue.push(kill);
        
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();
            ans.push_back(node);
            
            for(int &v: graph[node])
                queue.push(v);
        }
        
        return ans;
    }
};