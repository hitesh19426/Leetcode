class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int to_insert = 0, n = (int)nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                swap(nums[to_insert++], nums[i]);
            }
        }
    }
};