class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, last = -1;
        unordered_map<char, int> umap;
        
        for(auto i=0u; i<s.size(); i++){
            if(umap.find(s[i]) != umap.end())
                last = max(last, umap[s[i]]);
            
            int cur = i-last;
            ans = max(ans, cur);
            umap[s[i]] = i;
        }
        
        return ans;
    }
};