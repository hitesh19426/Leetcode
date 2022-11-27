class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0, ans = -1;
        int count[26] = {0}, total = 0;
        
        while(end < s.size()){
            count[s[end]-'A']++;
            
            while(end-start+1 - *max_element(count, count+26) > k && start <= end){
                count[s[start]-'A']--;
                start++;
            }
            
            ans = max(ans, end-start+1);
            end++;
        }
        
        return ans;
    }
};