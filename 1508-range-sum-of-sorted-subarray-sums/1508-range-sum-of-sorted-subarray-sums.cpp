class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subs;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                subs.push_back(sum);
            }
        }
        
        sort(subs.begin(), subs.end());        
        long long ans = 0, mod = 1e9+7;
        for(int i=left-1; i<right; i++){
            ans += subs[i];
            ans %= mod;
        }
        return ans;
    }
};