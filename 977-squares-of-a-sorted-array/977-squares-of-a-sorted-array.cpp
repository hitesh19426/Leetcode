class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int index = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        int ptr1 = index-1, ptr2 = index, n = nums.size();
        while(ptr1 >=0 && ptr2 < n){
            if(nums[ptr1]*nums[ptr1] < nums[ptr2]*nums[ptr2])
                ans.push_back(nums[ptr1]*nums[ptr1--]);
            else
                ans.push_back(nums[ptr2]*nums[ptr2++]);
        }
        
        while(ptr1 >= 0)
            ans.push_back(nums[ptr1]*nums[ptr1--]);
        while(ptr2 < n)
            ans.push_back(nums[ptr2]*nums[ptr2++]);
        
        return ans;
    }
};