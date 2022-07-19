class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        long long mod = 1e9+7, ans = 0;
        long long pow[arr.size()+1];
        pow[0] = 1;
        for(int i=1; i<=arr.size(); i++)
            pow[i] = (pow[i-1]*2)%mod;
        
        sort(arr.begin(), arr.end());
        
        for(int low=0, high = arr.size()-1; low<=high; low++){
            while(high >= low && arr[high] + arr[low] > target)
                high--;
            ans = (ans + (high < low ? 0 : pow[high - low]))%mod;
        }
        
        return ans;
    }
};