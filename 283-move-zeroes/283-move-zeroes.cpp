class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, n = (int)nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                zero++;
            else if(zero > 0){
                swap(nums[i], nums[i-zero]);
            }
        }
    }
};