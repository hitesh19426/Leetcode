class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0, ans = 0, unique = 0, window[128] = {};
        while(end < s.size()){
            if(window[s[end]]++ == 0)
                unique++;
            
            while(unique > 2 && start <= end){
                if(--window[s[start]] == 0)
                    unique--;
                start++;
            }
            
            ans = max(ans, end-start+1);
            end++;
        }
        
        return ans;
    }
};