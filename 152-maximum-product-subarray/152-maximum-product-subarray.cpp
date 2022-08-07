class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_dp[n], max_dp[n], ans = nums[0];
        min_dp[0] = max_dp[0] = nums[0];
        
        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                min_dp[i] = min(nums[i], max_dp[i-1]*nums[i]);
                max_dp[i] = max(nums[i], min_dp[i-1]*nums[i]);
            }else{
                min_dp[i] = min(nums[i], min_dp[i-1]*nums[i]);
                max_dp[i] = max(nums[i], max_dp[i-1]*nums[i]);
            }
            ans = max(ans, max_dp[i]);
        }
        
        return ans;
    }
};