class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int to_insert = 0, n = (int)nums.size();
        for(int i=0; i<n; i++){
            if(nums[i])
                nums[to_insert++] = nums[i];
        }
        while(to_insert < (int)nums.size()){
            nums[to_insert++] = 0;
        }
    }
};