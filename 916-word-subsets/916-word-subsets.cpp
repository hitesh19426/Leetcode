class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count[26] = {};
        for(auto &word: words2){
            int count1[26] = {};
            for(char &c: word){
                count1[c-'a']++;
            }
            
            for(int i=0; i<26; i++){
                count[i] = max(count[i], count1[i]);
            }
        }
        
        vector<string> ans;
        for(auto &word: words1){
            int count1[26] = {};
            for(char &c: word){
                count1[c-'a']++;
            }
            
            bool append = true;
            for(int i=0; i<26; i++){
                if(count1[i] < count[i]){
                    append = false;
                    break;
                }
            }
            if(append)
                ans.push_back(word);
        }
        
        return ans;
    }
};