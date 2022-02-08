class Solution {
public:
    int upper_bound(vector<int>& arr, int mid){
        if(mid == (int)arr.size()-1)
            return arr.size();
        if(arr[mid] != arr[mid+1])
            return mid+1;
        return mid+2;
    }
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int index = upper_bound(arr, mid);
            if(index&1)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return arr[ans];
    }
};