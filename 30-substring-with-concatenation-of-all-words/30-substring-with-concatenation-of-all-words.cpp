class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size(), m = words.size(), n = s.size();
        unordered_map<string, int> target, window;
        for(auto &word: words)
            target[word]++;
        
        vector<bool> valid(n, true);
        vector<int> ans;
        for(int i=0; i+m*len-1<n; i++){
            if(!valid[i])
                continue;
            
            window.clear();
            int done = true, j = i, rem = target.size();
            for(int count = 0; count<m; j+=len, count++){
                auto sub = s.substr(j, len);
                if(target.find(sub) == target.end()){
                    done = false;
                    break;
                }else if(++window[sub] == target[sub]){
                        rem--;
                }
            }
            
            if(done && rem == 0){
                ans.push_back(i);
            }
            else if(!done){
                for(int k=i; k<=j; k+=len){
                    valid[k] = false;
                }
            }
        }
        
        return ans;
    }
};