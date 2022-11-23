class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1, high = arr.size()-2, ind = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid-1] < arr[mid])
                ind = mid, low = mid+1;
            else
                high = mid-1;
        }
        return ind;
    }
};