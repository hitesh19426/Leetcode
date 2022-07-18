class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evensum = 0;
        for(int x: nums){
            if(x%2 == 0){
                evensum += x;
            }
        }
        
        vector<int> ans;
        for(auto &query: queries){
            int val = query[0], index = query[1];
            if(nums[index]%2 == 0)
                evensum -= nums[index];
            nums[index] += val;
            if(nums[index]%2 == 0)
                evensum += nums[index];
            
            ans.push_back(evensum);
        }
        return ans;
    }
};