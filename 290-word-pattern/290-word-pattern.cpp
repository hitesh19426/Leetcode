class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> wordmap(26, "");
        unordered_map<string, int> charmap;
        int i = 0, n = pattern.size();
        string word;
        stringstream ss(s);
        while(ss >> word){
            if(i == n){
                return false;
            }
            if(wordmap[pattern[i]-'a'] == "" && !charmap[word]){
                wordmap[pattern[i]-'a'] = word;
                charmap[word] = pattern[i];
            }
            else if(wordmap[pattern[i]-'a'] != word){
                return false;
            }
            else if(charmap[word] != pattern[i]){
                return false;
            }
            i++;
        }
        
        return pattern.size()==i;
        
    }
};