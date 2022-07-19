class Solution {
    int mod = 1e9+7;
    int binary_search(vector<int>& arr, int ind, int target){
        int low = ind+1, high = arr.size()-1, ans = ind;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[ind] + arr[mid] <= target)
                ans = mid, low=mid+1;
            else
                high = mid-1;
        }
        return ans - ind;
    }
    
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
        for(int i=0; i<arr.size(); i++){
            if(2*arr[i] > target)
                continue;
            int count = binary_search(arr, i, target);
            ans = (ans + pow(2, count))%mod;
        }
        
        return ans;
    }
};