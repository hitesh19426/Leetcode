class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 1e8;
        for(int i=0; i<nums.size(); i++){
            int low = i+1, high = nums.size()-1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(abs(sum - target) < abs(closest - target))
                    closest = sum;
                if(nums[low] + nums[high] == target - nums[i])
                    return target;
                if(nums[low] + nums[high] < target - nums[i])
                    low++;
                else
                    high--;
            }
        }
        
        return closest;
    }
};