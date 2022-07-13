class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        string start = "0000";

        if(deadends_set.find(start) != deadends_set.end())
            return -1;
        
        unordered_map<string, int> dist;
        queue<string> queue;
        queue.push(start);
        dist[start] = 0;
        
        while(not queue.empty()){
            auto pattern = queue.front();
            queue.pop();
            
            if(pattern == target)
                return dist[pattern];
            
            for(int i=0; i<4; i++){
                int digit = pattern[i]-'0';
                char up = '0'+(digit+1)%10, down = '0'+(digit-1+10)%10;
                string newp = pattern;
                
                newp[i] = up;
                if(deadends_set.find(newp) == deadends_set.end() && dist.find(newp) == dist.end()){
                    dist[newp] = dist[pattern]+1;
                    queue.push(newp);
                }
                
                newp[i] = down;
                if(deadends_set.find(newp) == deadends_set.end() && dist.find(newp) == dist.end()){
                    dist[newp] = dist[pattern]+1;
                    queue.push(newp);
                }
            }
        }
        
        return -1;
    }
};