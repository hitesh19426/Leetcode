class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        
        int count[128] = {}, window[128] = {}, remaining = 0;
        for(char c: t){
            if(count[c]++ == 0)
                remaining++;
        }
        
        int start = 0, end = 0, len = INT_MAX, start_index = -1;
        while(end < s.size()){
            if(++window[s[end]] == count[s[end]])
                remaining--;
            
            while(remaining == 0 && start <= end){
                if(end - start + 1 < len){
                    len = end-start+1, start_index = start;
                }
                if(window[s[start]]-- == count[s[start]])
                    remaining++;
                start++;
            }
            
            end++;
        }
        
        return (len == INT_MAX ? "" : s.substr(start_index, len));
    }
};