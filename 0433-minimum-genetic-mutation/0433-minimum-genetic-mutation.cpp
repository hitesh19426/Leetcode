class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        
        unordered_map<string, int> dist;
        queue<string> queue;
        
        queue.push(start);
        dist[start] = 0;
        
        vector<char> mutations{'A', 'C', 'G', 'T'};
        
        while(!queue.empty()){
            auto gene = queue.front();
            queue.pop();
            
            if(gene == end){
                return dist[gene];
            }
            
            auto newgene = gene;
            for(auto &c: newgene){
                char orig = c;
                for(char ch: mutations){
                    c = ch;
                    if(dict.find(newgene) != dict.end() && dist.find(newgene) == dist.end()){
                        queue.push(newgene);
                        dist[newgene] = dist[gene]+1;
                    }
                }
                c = orig;
            }
        }
        
        return -1;
    }
};