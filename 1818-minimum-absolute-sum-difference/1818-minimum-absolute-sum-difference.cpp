class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> seen(nums1.begin(), nums1.end());
        long max_gain = 0, sum = 0;
        for(int i=0; i<nums2.size(); i++){
            sum += abs(nums2[i] - nums1[i]);
            
            
            int diff = INT_MAX;
            auto itr = seen.lower_bound(nums2[i]);
            if(itr != seen.end())
                diff = *itr - nums2[i];
            if(itr != seen.begin())
                diff = min(diff, nums2[i] - *(--itr));
            
            int gain = abs(diff - abs(nums1[i] - nums2[i]));
            if(gain > max_gain){
                max_gain = gain;
            }
        }
        
        return (sum - max_gain)%1000'000'007;
    }
};