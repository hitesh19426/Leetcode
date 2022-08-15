class Solution {
public:
    bool neighbour(string& a, string& b){
        int count = 0;
        for(int i=0 ; i<a.length(); i++){
            if(a[i] != b[i])
                count++;
        }
        return count == 1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // If beginWord existed already, then delete it (using swapping method to delete it).
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        
        unordered_map<string, int> index; // word to index
        for(int i=0; i<wordList.size(); i++)
            index[wordList[i]] = i;
        if(index.find(endWord) == index.end())
            return {};
        
        // make undirected graph using indexes instead of words
        vector<vector<int>> graph(index.size());
        for(int i=0; i<wordList.size(); i++) {
            for(int j=i+1; j<wordList.size(); j++) {
                if(neighbour(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        // BFS  
        int start_node = index[endWord], target_node = index[beginWord];
        vector<int> dist(wordList.size(), INT_MAX);
        queue<int> queue1;
        
        dist[start_node] = 0;
        queue1.push(start_node);
        
        while(!queue1.empty()){
            auto node = queue1.front();
            queue1.pop();

            for(auto& v: graph[node]){
                if(dist[v] == INT_MAX){
                    dist[v] = dist[node] + 1;
                    queue1.push(v);
                }
            }
        }
        
        // If target is not reachable
        if(dist[target_node] == INT_MAX)
            return {};

        int min_dist = dist[target_node];
        queue<vector<int>> queue2;
        queue2.push({target_node});
        while(min_dist--) {
             int size = queue2.size();
             while(size--){
                auto path = queue2.front();
                queue2.pop();
                auto last = path.back();
                for (auto& v: graph[last]) {
                    if(dist[v] == min_dist){
                        path.push_back(v);
                        queue2.push(path);
                        path.pop_back();
                    }
                }
            }
        }
        
        vector<vector<string>> ans;
        while(!queue2.empty()) {
            vector<string> path;
            auto seq = queue2.front();
            queue2.pop();
            for(auto v: seq)
                path.push_back(wordList[v]);
            ans.push_back(path);
        }
        return ans;
    }
};