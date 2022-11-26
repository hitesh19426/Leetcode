class Solution {
    int countMissingNumberLessThanMid(vector<int>& arr, int mid){
        int total = mid;
        int present = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        return total - present;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = min(k, arr[0]+k), high = arr.back()+k, ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(countMissingNumberLessThanMid(arr, mid) >= k)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};