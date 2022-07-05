class Solution {
public:
    int missingElement(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, ind = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid]-arr[0]-mid < k)  // number of missing elements <= k
                ind = mid, low=mid+1;
            else
                high=mid-1;
        }
        
        return k + arr[0] + ind;
    }
};

// no of missing = total - present = arr[i]-(arr[0]-1) - (i+1) =  arr[i] - arr[0] - i