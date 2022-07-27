class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int min_index = 0, max_index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < nums[min_index])
                min_index = i;
            if(nums[i] >= nums[max_index])
                max_index = i;
        }
        
        return nums.size() - max_index -1 + min_index - (min_index > max_index);
    }
};