class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> index;
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            int res = 0;
            for(char c: s)
                res = 10*res + (mapping[c-'0']);
            index.push_back({res, i});
        }
        
        sort(index.begin(), index.end());
        
        vector<int> ans;
        for(auto &[res, ind]: index){
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};