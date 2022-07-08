class Solution {
public:
    int findMin(vector<int>& nums) {
        int peak = -1, low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= nums[0])
                peak = mid, low = mid+1;
            else
                high = mid-1;
        }
        
        return min(nums[0], (peak+1 == nums.size() ? INT_MAX : nums[peak+1]));
    }
};