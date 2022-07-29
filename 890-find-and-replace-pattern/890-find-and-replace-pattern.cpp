class Solution {
    bool check(string &s, string &p){
        vector<char> maps(26, '.'), mapp(26, '.');
        for(int i=0; i<s.size(); i++){
            if(maps[s[i] - 'a'] == '.' && mapp[p[i]-'a'] != '.')
                return false;
            if(maps[s[i] - 'a'] != '.' && mapp[p[i]-'a'] != s[i])
                return false;
            
            maps[s[i]-'a'] = p[i];
            mapp[p[i]-'a'] = s[i];
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &word: words){
            if(check(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }
};