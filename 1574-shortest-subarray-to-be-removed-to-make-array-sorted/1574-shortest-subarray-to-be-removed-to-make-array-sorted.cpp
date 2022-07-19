class Solution {
    bool check(vector<pair<bool, int>>& prefix, vector<pair<bool, int>> &suffix, int mid){
        int n = prefix.size()-1;
        for(int i=0, j=mid-1; j<n; i++, j++){
            if(prefix[i].first && suffix[j+1].first && prefix[i].second <= suffix[j+1].second)
                return true;
        }
        return false;
    }
    
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<pair<bool, int>> prefix(arr.size()+1);
        prefix[0] = {true, INT_MIN};
        for(int i=0; i<arr.size(); i++){
            bool prefix_is_sorted = (prefix[i].first && arr[i] >= prefix[i].second);
            int prefix_max = max(prefix[i].second, arr[i]);
            prefix[i+1] = {prefix_is_sorted, prefix_max};
        }
        
        vector<pair<bool, int>> suffix(arr.size()+1);
        suffix[n] = {true, INT_MAX};
        for(int i=arr.size()-1; i>=0; i--){
            bool suffix_is_sorted = (suffix[i+1].first && suffix[i+1].second >= arr[i]);
            int suffix_min = min(suffix[i+1].second, arr[i]);
            suffix[i] = {suffix_is_sorted, suffix_min};
        }
        
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(prefix, suffix, mid))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};