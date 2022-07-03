class Solution {
    int findSign(int a){
        if(a == 0)
            return 0;
        return (a>0 ? 1 : -1);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int n = nums.size(), last = findSign(nums[1] - nums[0]), len = 1 + (last != 0);
        for(int i=2; i<n; i++){
            int curr = findSign(nums[i] - nums[i-1]);
            if(curr != 0 && curr != last){
                last = curr;
                len++;
            }
        }
        
        return len;
    }
};