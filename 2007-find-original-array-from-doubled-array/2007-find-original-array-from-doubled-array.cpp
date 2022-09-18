class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> seen;
        for(int &x: changed)
            seen[x]++;
        
        vector<int> ans;
        for(auto [x, count]: seen){
            if(x == 0){
                if(count&1)
                    return {};
                for(int i=0; i<count/2; i++){
                    ans.push_back(x);
                }
                continue;
            }
            
            if(seen.find(2*x) == seen.end() || seen[x] > seen[2*x]){
                return {};
            }
            for(int i=0; i<count; i++)
                ans.push_back(x);
            seen[2*x] -= count;
            if(seen[2*x] == 0)
                seen.erase(2*x);
        }
        
        return ans;
    }
};