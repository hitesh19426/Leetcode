class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0, seq_size = (1<<arr.size());
        
        for(int seq=0; seq<seq_size; seq++){
            int count[26] = {}, len = 0, proceed = true;
            for(int j=0; j<arr.size(); j++){
                if(seq&(1<<j)){
                    len += arr[j].size();
                    for(auto &c: arr[j]){
                        if(++count[c-'a'] > 1)
                            proceed = false;
                    }
                    if(proceed == false)
                        break;
                }
            }
            
            if(proceed)
                ans = max(ans, len);
        }
        
        return ans;
    }
};