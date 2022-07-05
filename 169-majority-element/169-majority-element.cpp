class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int score = 0, can = nums[0];
        
        for(const int &num:nums){
            num == can ? score++ : score--;
            if(score == 0){
                score = 1, 
                can = num;
            }
        }
        
        return can;
    }
};