class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> seen;
        unordered_map<int, int> lost;
        
        for(auto &match: matches){
            seen.insert(match[0]);
            seen.insert(match[1]);
            lost[match[1]]++;
        }
        
        vector<int> ans1, ans2;
        for(auto x: seen){
            if(lost.find(x) == lost.end()){
                ans1.push_back(x);
            }else if(lost[x] == 1){
                ans2.push_back(x);
            }
        }
        
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        
        return vector<vector<int>>{ans1, ans2};
    }
};