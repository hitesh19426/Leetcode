class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr{1};
        for(int x: nums){
            arr.push_back(x);
        }
        arr.push_back(1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int len=0; len<n; len++){
            for(int left=1; len+left<=n; left++){
                int right = left+len;
                
                for(int k=left; k<=right; k++)
                    dp[left][right] = max(dp[left][right], dp[left][k-1] + dp[k+1][right] + arr[left-1]*arr[k]*arr[right+1]);
                
            }
        }
        
        return dp[1][n];
        // return 0;
    }
};