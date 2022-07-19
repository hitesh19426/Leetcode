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
        
        nth_element(subs.begin(), subs.begin()+right-1, subs.end());
        nth_element(subs.begin(), subs.begin()+left-1, subs.begin()+right-1);
        long long ans = 0, mod = 1e9+7;
        for(int i=left-1; i<right; i++){
            ans += subs[i];
            ans %= mod;
        }
        return ans;
    }
};