class Solution {
    int replace_and_sum(vector<int>& arr, vector<int>& prefix, int mid){
        int ind = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        // cout << "mid, ind = " << mid << " "  << ind << endl;
        if(ind == arr.size())
            return prefix.back();
        return prefix[ind] + (arr.size()-ind)*mid;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        vector<int> prefix(arr.size()+1, 0);
        for(int i=0; i<arr.size(); i++)
            prefix[i+1] = arr[i] + prefix[i];
        
        int n = arr.size(), low = 0, high = arr[n-1], ans = -1, closest_sum = -1e6;
        while(low <= high){
            int mid = (low+high)/2;
            int sum = replace_and_sum(arr, prefix, mid);
            
            if(sum == target)
                return mid;
            if(abs(sum - target) < abs(closest_sum - target))
                ans = mid, closest_sum = sum;
            else if(abs(sum - target) == abs(closest_sum - target))
                ans = min(ans, mid);
            if(sum < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return ans;
        
    }
};