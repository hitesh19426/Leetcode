class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> index;
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            int res = 0;
            for(char c: s)
                res = 10*res + (mapping[c-'0']);
            index[res].push_back(i);
        }
        
        vector<int> ans;
        for(auto &pair: index){
            for(auto &ind: pair.second){
                ans.push_back(nums[ind]);
            }
        }
        return ans;
    }
};