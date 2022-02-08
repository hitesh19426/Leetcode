class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if( (mid == 0 || arr[mid]>arr[mid-1]) && (mid == arr.size()-1 || arr[mid] > arr[mid+1]) ) {
                return mid;
            }
            else if(mid == 0 || arr[mid-1] < arr[mid]){
                ans = mid, low = mid+1;
            }
            else{
                ans = mid, high = mid-1;
            }
        }
        return ans;
    }
};