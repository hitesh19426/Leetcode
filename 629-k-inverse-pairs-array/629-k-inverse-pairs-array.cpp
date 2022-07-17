class Solution {
public:
    int kInversePairs(int n, int target) {
        int mod = 1e9+7;
        vector<long long> prev(target+1, 0), prefix(target+2, 0);
        
        for(int i=1; i<=n; i++){
            vector<long long> curr(target+1, 0);
            curr[0] = 1;
            for(int j=1; j<=target; j++){
                int left = max(0, j-i+1), right = j;
                curr[j] = (prefix[right+1] - prefix[left]+mod)%mod;
            }
            prefix[0] = 0;
            for(int i=0; i<=target; i++)
                prefix[i+1] = (prefix[i]+curr[i])%mod;
        }
        
        return (prefix[target+1] - prefix[target] + mod)%mod;
    }
};