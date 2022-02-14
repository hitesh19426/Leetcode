class Solution {
public:
    int count(vector<int>& arr, int low, int high, int target){
        int start = low-1, index = low-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] < target)
                index = mid, low=mid+1;
            else
                high=mid-1;
        }
        return index-start;
    }
    
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                ans += count(arr, j+1, arr.size()-1, arr[i]+arr[j]);
            }
        }
        return ans;
    }
};