class Solution {
    int findMaxSubstringWithMUniqueChar(string &s, int max_unique, int k){
        int start = 0, end = 0, window[26] = {}, unique = 0, count_greater_equal_than_k = 0, ans = 0;
        while(end < s.size()){
            int windowEnd = s[end]-'a';
            if(window[windowEnd]++ == 0)
                unique++;
            if(window[windowEnd] == k)
                count_greater_equal_than_k++;
            
            if(unique == max_unique && count_greater_equal_than_k == unique)
                ans = max(ans, end-start+1);
            
            while(unique > max_unique && start <= end){
                int windowStart = s[start]-'a';
                if(window[windowStart] == k)
                    count_greater_equal_than_k--;
                if(--window[windowStart] == 0)
                    unique--;
                start++;
            }
            
            end++;
        }
        
        return ans;
    }
public:
    int longestSubstring(string s, int k) {
        int count[26] = {}, unique = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            if(count[s[i]-'a']++ == 0)
                unique++;
        }
        
        for(int i=1; i<=unique; i++)
            ans = max(ans, findMaxSubstringWithMUniqueChar(s, i, k));
        return ans;
    }
};