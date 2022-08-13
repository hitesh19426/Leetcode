class Solution {
    void helper(vector<int>& arr, int ind, int target, vector<int>& path, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(target < 0 || ind == arr.size()){
            return;
        }
        
        helper(arr, ind+1, target, path, res);
        
        path.push_back(arr[ind]);
        helper(arr, ind, target - arr[ind], path, res);
        path.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> path;
        helper(arr, 0, target, path, res);
        return res;
    }
};