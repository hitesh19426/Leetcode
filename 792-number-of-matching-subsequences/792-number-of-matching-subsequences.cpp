class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(26, vector<int>());
        for(int i=0; i<s.size(); i++){
            index[s[i]-'a'].push_back(i);
        }
        
        int count = 0;
        for(auto &word: words){
            int ind = -1, done = true;
            for(auto &c: word){
                auto itr = upper_bound(index[c-'a'].begin(), index[c-'a'].end(), ind);
                if(itr == index[c-'a'].end()){
                    done = false;
                    break;
                }
                ind = *itr;
            }
            if(done)
                count++;
        }
        
        return count;
    }
};