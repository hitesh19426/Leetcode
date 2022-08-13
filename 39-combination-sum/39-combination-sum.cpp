class Solution {
    vector<vector<int>> helper(vector<int>& arr, int ind, int target){
        if(target == 0)
            return {{}};
        if(target < 0 || ind < 0)
            return {};
        
        auto with = helper(arr, ind, target - arr[ind]);
        auto without = helper(arr, ind-1, target);
        
        auto& res = without;
        for(auto &seq: with){
            seq.push_back(arr[ind]);
            res.push_back(seq);
        }
        
        return res;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates, candidates.size()-1, target);
    }
};