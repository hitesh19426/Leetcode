class Solution {
    void helper(vector<int>& arr, int ind, vector<vector<int>>& res){
        if(ind == arr.size()){
            res.push_back(arr);
            return;
        }
        
        for(int i=ind; i<arr.size(); i++){
            swap(arr[ind], arr[i]);
            helper(arr, ind+1, res);
            swap(arr[ind], arr[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
};