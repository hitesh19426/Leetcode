class Solution {
    int mod = 1e9+7;
    int pow(long long x, int n){
        long long res = 1;
        while(n){
            if(n&1)
                res = (res*x)%mod;
            x = (x*x)%mod;
            n /= 2;
        }
        return res;
    }
public:
    int numSubseq(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        long long ans = 0;
        for(int low=0, high = arr.size()-1; low<=high; low++){
            while(high >= low && arr[high] + arr[low] > target)
                high--;
            if(high < low)
                break;
            ans = (ans + pow(2, high - low))%mod;
        }
        
        return ans;
    }
};