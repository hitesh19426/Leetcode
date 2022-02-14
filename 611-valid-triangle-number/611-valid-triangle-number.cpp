class Solution {
public:
    int count(vector<int>& arr, int low, int high, int target){
        int n = high+1, index = high+1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] > target)
                index = mid, high=mid-1;
            else
                low=mid+1;
        }
        return n - index;
    }
    
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for(int i=arr.size()-1; i>=0; i--){
            for(int j=i-1; j>=0; j--){
                ans += count(arr, 0, j-1, arr[i]-arr[j]);
            }
        }
        return ans;
    }
};