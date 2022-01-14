class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        
        if(i != -1){
            int low = i+1, high = nums.size()-1, index = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(nums[mid] > nums[i])
                    index = mid, low = mid+1;
                else
                    high = mid-1;
            }
            swap(nums[i], nums[index]);
        }
        
        reverse(nums.begin()+i+1, nums.end());
    }
};