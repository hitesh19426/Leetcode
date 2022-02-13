class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target)
                return true;
            if(arr[low] == arr[mid]){
                low++;
                continue;
            }
            
            bool targetOnLeft = (target >= arr[low]), midOnLeft = (arr[mid] >= arr[low]);
            if(targetOnLeft ^ midOnLeft){
                (targetOnLeft ? high = mid-1 : low = mid+1);
            }
            else{
                (target < arr[mid] ?  high = mid-1 : low = mid+1);
            }
        }
        
        return false;
    }
};