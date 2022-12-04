class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long ans = LLONG_MAX, sum = 0;
        int ind = -1, n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0ll);
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int diff = abs(sum/(i+1) - (total-sum)/(i == n-1 ? 1 : n-i-1));
            if(diff < ans)
                ans = diff, ind = i;
        }
        
        return ind;
    }
};