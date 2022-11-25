class Solution {
public:
    int search_pivot(vector<int> &arr){
        int low = 0, high = arr.size()-1, pivot = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] < arr[0]){
                pivot = mid, high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return pivot;
    }
    
    int binary_search(vector<int> &arr, int target, int low, int high){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = search_pivot(nums);
        
        int ind1 = binary_search(nums, target, 0, pivot-1);
        
        if(ind1==-1)
            return binary_search(nums, target, pivot, nums.size()-1);
        return ind1;
    }
};