class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        long long minvalue = *min_element(nums.begin(), nums.end());
        
        int ans = sum - minvalue*(nums.size());
        return ans;
    }
};