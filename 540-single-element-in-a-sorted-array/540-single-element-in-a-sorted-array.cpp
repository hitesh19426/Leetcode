class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int index = upper_bound(arr.begin(), arr.end(), arr[mid]) - arr.begin();
            if(index&1)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return arr[ans];
    }
};