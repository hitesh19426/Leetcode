class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0, ans = 0;
        map<char, int> window;
        while(end < s.size()){
            window[s[end]]++;
            
            while(window.size() > 2 && start <= end){
                if(--window[s[start]] == 0)
                    window.erase(s[start]);
                start++;
            }
            
            ans = max(ans, end-start+1);
            end++;
        }
        
        return ans;
    }
};