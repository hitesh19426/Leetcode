class Solution {
    int calculateMoveSuffix(int j, int ind, long long target, vector<long long>& prefix){
        // (arr[ind]-arr[j]) + (arr[ind]-arr[j+1]) + (arr[ind]-arr[j+2]) + () + ... + (arr[ind]-arr[ind])
        return (long long)target*(ind-j) - (prefix[ind] - prefix[j]);
    }
    
    int maxEqualElementsAfterMoves(long long target, vector<long long>& prefix, int ind, int k){
        int low = 0, high = ind-1, ans = ind;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(calculateMoveSuffix(mid, ind, target, prefix) <= k)
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
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            prefix.push_back(prefix.back()+arr[i]);
            ans = max(ans, maxEqualElementsAfterMoves(arr[i], prefix, i, k));
        }
        return ans;
    }
};