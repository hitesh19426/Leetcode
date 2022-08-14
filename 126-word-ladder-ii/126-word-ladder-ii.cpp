class Solution {
public:
    bool neighbour(string& a, string& b){
        int cnt = 0 ;
        for(int i = 0 ; i < a.length() ; i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1 ;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // insert beginWord in wordList
        wordList.insert(wordList.begin(), beginWord);
        
        // If beginWord existed already, then delete it (using swapping method to delete it).
        for(int i=1; i<wordList.size(); i++){
            if(wordList[i] == wordList[0]) {
                wordList[i] = wordList.back();
                wordList.pop_back();
                break;
            }   
        }
        map<string, int> wti ; // word to index
        for(int i=0; i<wordList.size(); i++)
            wti[wordList[i]] = i;
        if(wti.find(endWord) == wti.end()) 
            return {};
        
        // make undirected graph using indexes of nodes instead of words
        vector<vector<int>> edges(wti.size());
        for(int i=0; i<wordList.size(); i++) {
            for(int j=i+1; j<wordList.size(); j++) {
                if(neighbour(wordList[i], wordList[j])){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        
        // BFS  
        int start_node = 0, target_node = wti[endWord], r = 0;
        vector<int> dist(wordList.size(), INT_MAX);
        queue<int> q;
        
        dist[start_node] = 0;
        q.push(start_node);
        while(!q.empty()){
            int fr = q.front();
            q.pop();

            for(int& v: edges[fr]) {
                if(dist[v] > dist[fr] + 1) {
                    dist[v] = dist[fr] + 1;
                    q.push(v);
                }
            }
        }
        
        if(dist[target_node] == INT_MAX)
            return {} ;

        queue<vector<string>> q2 ; 
        q2.push({wordList[target_node]}) ;
        r = dist[target_node] ;
        while(r) {
             int sz  = q2.size() ;
             for(int i = 0 ; i < sz ; i++) {
                vector<string> seq = q2.front() ;
                q2.pop();
                string back = seq.back() ;
                int curr = wti[back] ;
                for (int j = 0 ; j < edges[curr].size() ; j++) {
                    int new_node = edges[curr][j] ;
                    if (dist[new_node] == r - 1) {
                        seq.push_back(wordList[new_node]) ;
                        q2.push(seq) ;
                        seq.pop_back() ;
                    }
                }
            }
            r-- ;
        }
        
        vector<vector<string>> ans;
        while(!q2.empty()) {
            vector<string> temp = q2.front() ;
            q2.pop() ;
            reverse(begin(temp) , end(temp)) ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};