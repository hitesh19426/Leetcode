class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negative, positive;
        int index = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        for(int i=index-1; i>=0; i--)
            negative.push_back(nums[i]*nums[i]);
        for(int i=index; i<(int)nums.size(); i++)
            positive.push_back(nums[i]*nums[i]);
        
        vector<int> ans;
        int ptr1 = 0, ptr2 = 0, m = negative.size(), n = positive.size();
        while(ptr1 < m && ptr2 < n){
            if(negative[ptr1] < positive[ptr2])
                ans.push_back(negative[ptr1++]);
            else
                ans.push_back(positive[ptr2++]);
        }
        
        while(ptr1 < m)
            ans.push_back(negative[ptr1++]);
        while(ptr2 < n)
            ans.push_back(positive[ptr2++]);
        
        return ans;
    }
};