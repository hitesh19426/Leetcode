class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, ind = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] - (mid+1) < k)
                ind = mid, low = mid+1;
            else
                high = mid-1;
        }
        if(ind == -1)
            return k;
        return arr[ind] + k - (arr[ind] - (ind+1));
    }
};