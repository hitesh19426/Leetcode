class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(is_sorted(arr.begin(), arr.end()))
            return 0;
        
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
        
        int start = 0, end = 0, ans = INT_MAX;
        while(end < arr.size()){
            
            while(suffix[end+1].first && prefix[start].first && prefix[start].second <= suffix[end+1].second && start <= end){
                ans = min(ans, end-start+1);
                start++;
            }
            
            end++;
                
        }
        return ans;
    }
};