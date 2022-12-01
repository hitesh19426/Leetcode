class Solution {
public:
    int calculateTime(string s, string word) {
        int index[26] = {};
        for(int i=0; i<s.size(); i++)
            index[s[i]-'a'] = i;
        
        int ans = 0, last = 0;
        for(char c: word){
            ans += abs(index[c-'a'] - last);
            last = index[c-'a'];
        }
        
        return ans;
    }
};