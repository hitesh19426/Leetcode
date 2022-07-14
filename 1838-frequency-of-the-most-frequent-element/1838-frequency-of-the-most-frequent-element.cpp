class Solution {
    int calculateMoveSuffix(int j, int ind, long long target, vector<long long>& prefix){
        return (long long)target*(ind-j) - (prefix[ind] - prefix[j]);
    }
    
    int maxEqualElementsAfterMoves(long long target, vector<long long>& prefix, int ind, int k){
        int low = 0, high = ind-1, ans = ind;
        while(low <= high){
            int mid = low+(high-low)/2;
            long long total = target*(ind-mid), left = (prefix[ind] - prefix[mid]);
            if(total - left <= k)
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
/*
T(n) = n*logn
S(n) = O(n)
*/