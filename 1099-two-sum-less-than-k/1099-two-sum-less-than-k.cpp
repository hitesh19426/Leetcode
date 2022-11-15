class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size()-1, ans = -1;
        while(low < high){
            if(nums[low] + nums[high] < k){
                ans = max(ans, nums[low++]+nums[high]);
            }else{
                high--;
            }
        }
        
        return ans;
    }
};