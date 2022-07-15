class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0ll), prefix = 0;
        
        int count = 0;
        for(int i=0; i<nums.size()-1; i++){
            prefix += nums[i];
            if(prefix >= total - prefix)
                count++;
        }
        return count;
    }
};