class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target)
                return true;
            if(arr[mid] == arr[low]){
                low++;
                continue;
            }
            
            bool midInFirstHalf = (arr[mid] >= arr[low]);
            bool targetInFirstHalf = (target >= arr[low]);
            
            if(midInFirstHalf ^ targetInFirstHalf){ // different half
                if(targetInFirstHalf)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{   // same half
                if(arr[mid] > target)
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        
        return false;
    }
};