class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n], count[n];
        
        for(int i=0; i<n; i++){
            dp[i] = 1, count[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i])
                        dp[i] = dp[j]+1, count[i] = count[j];
                    else if(dp[j] + 1 == dp[i])
                        dp[i] = dp[j]+1, count[i]+=count[j];
                }
            }
        }
        
        int ans = 0, max_len = 0;
        for(int i=0; i<n; i++){
            if(dp[i] > max_len)
                max_len = dp[i], ans = count[i];
            else if(dp[i] == max_len)
                ans += count[i];
        }
        return ans;
    }
};