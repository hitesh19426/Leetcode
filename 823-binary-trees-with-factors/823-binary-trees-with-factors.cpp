class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), mod = 1e9+7;
        vector<long long> dp(n, 1);
        
        for(int i=0; i<n; i++){
            int low = 0, high = i-1;
            while(low <= high){
                if((long long)arr[low]*arr[high] == arr[i]){
                    if(low == high)
                        dp[i] += dp[low]*dp[high];
                    else
                        dp[i] += dp[low]*dp[high]*2;
                    dp[i] %= mod;
                    low++, high--;
                }
                else if((long long)arr[low]*arr[high] < arr[i])
                    low++;
                else
                    high--;
            }
        }
        
        long long ans = 0;
        for(auto& x: dp)
            ans = (ans+x)%mod;
        return ans;
    }
};