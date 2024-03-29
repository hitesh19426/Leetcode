class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> lastfull;
        set<int> zeroes;
        vector<int> ans(rains.size(), -1);
        
        for(int i=0; i<rains.size(); i++){
            if(rains[i] == 0){
                zeroes.insert(i);
            }
            else{
                if(lastfull.find(rains[i]) != lastfull.end()){
                    int last = lastfull[rains[i]];
                    auto zero = zeroes.upper_bound(last);
                    if(zero == zeroes.end())
                        return {};
                    ans[*zero] = rains[i];
                    zeroes.erase(zero);
                }
                lastfull[rains[i]] = i;
            } 
        }
        for(auto zero: zeroes){
            ans[zero] = 1;
        }
        
        return ans;
    }
};