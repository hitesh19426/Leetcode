class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(is_sorted(arr.begin(), arr.end()))
            return 0;
        
        vector<pair<bool, int>> suffix(arr.size()+1);
        suffix[arr.size()] = {true, INT_MAX};
        for(int i=arr.size()-1; i>=0; i--){
            bool suffix_is_sorted = (suffix[i+1].first && suffix[i+1].second >= arr[i]);
            int suffix_min = min(suffix[i+1].second, arr[i]);
            suffix[i] = {suffix_is_sorted, suffix_min};
        }
        
        int start = 0, end = 0, ans = INT_MAX, pre_max = INT_MIN, issorted = true;
        while(end < arr.size()){
            while(suffix[end+1].first && issorted && pre_max <= suffix[end+1].second && start <= end){
                ans = min(ans, end-start+1);
                
                issorted &= (arr[start] >= pre_max);
                pre_max = max(pre_max, arr[start]);
                start++;
            }
            
            end++;
        }
        return ans;
    }
};