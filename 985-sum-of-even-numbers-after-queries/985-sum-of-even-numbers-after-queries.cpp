class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(int& x: nums){
            if(x%2 == 0)
                sum += x;
        }
        
        vector<int> ans;
        for(auto &query: queries){
            int val = query[0], ind = query[1];
            if(nums[ind]%2==0)
                sum -= nums[ind];
            nums[ind] += val;
            if(nums[ind]%2 == 0)
                sum += nums[ind];
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};