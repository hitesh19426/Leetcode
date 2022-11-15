class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix_sum(nums.size());
        partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
        return prefix_sum;
    }
};