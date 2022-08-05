class Solution {
    vector<int> dp;
    int helper(int target, vector<int>& nums){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int x: nums)
            ans += helper(target-x, nums);
        
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target+1, -1);
        return helper(target, nums);
    }
};