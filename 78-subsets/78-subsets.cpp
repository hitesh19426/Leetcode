class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        
        for(int i=0; i<nums.size(); i++){
            int size = ans.size();
            for(int j=0; j<size; j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
/*
T(N) = 2^N
*/