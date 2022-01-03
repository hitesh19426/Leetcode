class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int ptr1 = 0, ptr2 = n-1, k = n-1;
        while(ptr1 <= ptr2){
            if(abs(nums[ptr1]) < abs(nums[ptr2]))
                ans[k--] = nums[ptr2]*nums[ptr2--];
            else
                ans[k--] = nums[ptr1]*nums[ptr1++];
        }
        
        return ans;
    }
};