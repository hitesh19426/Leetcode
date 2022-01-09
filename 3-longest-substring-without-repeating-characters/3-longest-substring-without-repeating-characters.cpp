class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, last = -1;
        int umap[256];
        memset(umap, -1, sizeof(umap));
        
        for(int i=0; i<(int)s.size(); i++){
            cout << last << " " << umap[s[i]];
            last = max(last, umap[s[i]]);
            ans = max(ans, i-last);
            umap[s[i]] = i;
        }
        
        return ans;
    }
};