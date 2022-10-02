class Solution {
    int mod = 1e9+7;
    vector<vector<int>> dp;
    
    long long helper(int n, int target, int k){
        if(target < 0)
            return 0;
        if(n == 0)
            return (target == 0 ? 1 : 0);
        if(dp[n][target] != -1)
            return dp[n][target];
        
        long long ans = 0;
        for(int i=1; i<=k; i++)
            ans += helper(n-1, target-i, k);
        return dp[n][target] = ans%mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n+1, vector<int>(target+1, -1));
        return helper(n, target, k);
    }
};