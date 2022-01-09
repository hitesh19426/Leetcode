class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0; i<(int)nums.size(); i++){
            if(abs(nums[i]-i)>1)
                return false;
        }
        return true;
    }
};