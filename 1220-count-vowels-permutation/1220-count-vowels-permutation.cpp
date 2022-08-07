typedef long long ll;
class Solution {
public:
    int countVowelPermutation(int n) {
        long long aprev = 1, eprev = 1, iprev = 1, oprev = 1, uprev = 1, mod = 1e9+7;
        for(int j=2; j<=n; j++){
            ll a = (eprev + iprev + uprev)%mod;
            ll e = (aprev + iprev)%mod;
            ll i = (eprev + oprev)%mod;
            ll o = (iprev)%mod;
            ll u = (iprev + oprev)%mod;
            aprev = a, eprev = e, iprev = i, oprev = o, uprev = u;
        }
        
        return (aprev + eprev + iprev + oprev + uprev)%mod;
    }
};