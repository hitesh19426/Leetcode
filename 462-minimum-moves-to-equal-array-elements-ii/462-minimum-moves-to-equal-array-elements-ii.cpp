class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int target = nums[nums.size()/2];
        
        int ans = 0;
        for(auto& x:nums){
            ans += abs(x-target);
        }
        return ans;   
    }
};