class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        
        int done = 0;
        while(done != target.size()){
            bool anymatch = false;
            for(int i=0; i+stamp.size()-1<target.size(); i++){
                bool match = true;
                int question = 0;
                for(int j=0; j<stamp.size(); j++){
                    if(target[i+j] == stamp[j])
                        continue;
                    else if(target[i+j] == '?')
                        question++;
                    else{
                        match = false;
                        break;
                    }
                }
                
                if(match && question != stamp.size()){
                    memset(&target[i], '?', stamp.size());
                    ans.push_back(i);
                    done += stamp.size()-question;
                    anymatch = true;
                }
            }
            
            if(!anymatch)
                return {};
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};