class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> indexes(26, vector<pair<int, int>>());
        for(int i=0; i<words.size(); i++){
            indexes[words[i][0]-'a'].push_back({i, 0});
        }
        
        int count = 0;
        for(auto &c: s){
            auto curr = indexes[c-'a'];
            indexes[c-'a'].clear();
            
            for(auto &[index, letter]: curr){
                auto &word = words[index];
                if(letter+1 == word.size())
                    count++;
                else
                    indexes[word[letter+1]-'a'].push_back({index, letter+1});
            }
        }
        
        return count;
    }
};