class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, bottom = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] < nums[0])
                bottom = mid, high = mid-1;
            else
                low = mid+1;
        }
        
        return nums[bottom];
    }
};