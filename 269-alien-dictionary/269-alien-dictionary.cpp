class Solution {
    bool compare(string &a, string &b, unordered_map<char, vector<char>>& graph){
        int len = min(a.size(), b.size());
        for(int i=0; i<len; i++){
            if(a[i] != b[i]){
                graph[a[i]].push_back(b[i]);
                return true;
            }
        }
        return a.size() <= b.size();
    }
    
    void topoSort(char node, vector<bool>& vis, unordered_map<char, vector<char>>& graph, string &order){
        vis[node-'a'] = true;
        for(auto v: graph[node]){
            if(!vis[v])
                topoSort(v, vis, graph, order);
        }
        order += node;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        for(int i=0; i<words.size()-1; i++){
            if(compare(words[i], words[i+1], graph) == false)
                return "";
        }
        
        for(auto &word: words){
            for(char& c: word){
                if(graph.find(c) == graph.end())
                    graph[c] = vector<char>();
            }
        }
        
        queue<char> queue;
        vector<int> indegree(26, 0);
        
        for(auto &[src, edges]: graph){
            for(auto& v: edges)
                indegree[v-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(indegree[i] == 0 && graph.find('a'+i) != graph.end()){
                queue.push('a'+i);
            }
        }
        
        int rem = graph.size();
        string order = "";
        while(!queue.empty()){
            auto node = queue.front();
            queue.pop();
            order += node;
            rem--;
            
            for(auto v: graph[node]){
                if(--indegree[v-'a'] == 0){
                    queue.push(v);
                }
            }
        }
        
        return (rem == 0 ? order : "");
    }
};