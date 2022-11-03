class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        
        for(int seq=0; seq<(1<<arr.size()); seq++){
            int count[26] = {}, len = 0;
            for(int j=0; j<arr.size(); j++){
                if(seq&(1<<j)){
                    for(auto &c: arr[j])
                        count[c-'a']++;
                    len += arr[j].size();
                }
            }
            
            bool proceed = true;
            for(int i=0; i<26; i++){
                if(count[i] > 1)
                    proceed = false;
            }
            
            if(proceed){
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};