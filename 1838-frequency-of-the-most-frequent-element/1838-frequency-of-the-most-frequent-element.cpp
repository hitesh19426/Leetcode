class Solution {
    int calculateMoveSuffix(int j, int ind, vector<int>& arr, vector<long long>& prefix){
        // (arr[ind]-arr[j]) + (arr[ind]-arr[j+1]) + (arr[ind]-arr[j+2]) + () + ... + (arr[ind]-arr[ind])
        return (long long)arr[ind]*(ind-j+1) - (prefix[ind+1] - prefix[j]);
    }
    
    int maxEqualElementsAfterMoves(vector<int>& arr, vector<long long>& prefix, int ind, int k){
        int low = 0, high = ind, ans = ind;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(calculateMoveSuffix(mid, ind, arr, prefix) <= k)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ind-ans+1;
    }
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        vector<long long> prefix{0};
        for(long long x: arr)
            prefix.push_back(x + prefix.back());
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            ans = max(ans, maxEqualElementsAfterMoves(arr, prefix, i, k));
        }
        return ans;
    }
};