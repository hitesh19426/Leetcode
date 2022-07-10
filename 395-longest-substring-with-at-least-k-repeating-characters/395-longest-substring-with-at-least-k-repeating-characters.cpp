class Solution {
    int helper(string &s, int low, int high, int k){
        if(high-low+1 < k)
            return 0;
        
        int count[26] = {};
        for(int i=low; i<=high; i++)
            count[s[i]-'a']++;
        
        int mid = low;
        while(mid <= high && count[s[mid]-'a'] >= k)
            mid++;
        if(mid == high+1)
            return high - low + 1;
        return max(helper(s, low, mid-1, k), helper(s, mid+1, high, k));
    }
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size()-1, k);
    }
};