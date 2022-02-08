class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2, index;
            
            if(mid == (int)arr.size()-1)
                index = arr.size();
            else if(arr[mid] != arr[mid+1])
                index = mid+1;
            else
                index = mid+2;
            
            if(index&1)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return arr[ans];
    }
};