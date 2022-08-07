typedef long long ll;
class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[n+1][5], mod = 1e9+7;
        long long aprev = 1, eprev = 1, iprev = 1, oprev = 1, uprev = 1;
        for(int j=2; j<=n; j++){
            ll a = (eprev + iprev + uprev)%mod;
            ll e = (aprev + iprev)%mod;
            ll i = (eprev + oprev)%mod;
            ll o = (iprev)%mod;
            ll u = (iprev + oprev)%mod;
            // dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
            // dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            // dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            // dp[i][3] = dp[i-1][2]%mod;
            // dp[i][4] = (dp[i-1][2] + dp[i-1][3])%mod;
            
            aprev = a, eprev = e, iprev = i, oprev = o, uprev = u;
        }
        
        return (aprev + eprev + iprev + oprev + uprev)%mod;
        // return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4])%mod;
    }
};