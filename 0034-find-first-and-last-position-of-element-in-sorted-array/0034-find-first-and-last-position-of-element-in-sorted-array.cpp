class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(left == right)
            return vector<int>{-1, -1};
        return vector<int>{left, right-1};
    }
};