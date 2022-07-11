class Solution {
    int findClosest(set<int>& seen, int x){
        auto itr = seen.lower_bound(x);
        int closest = INT_MAX;
        if(itr != seen.end())
            closest = *itr;
        if(itr != seen.begin() && abs(*(--itr)-x) <  abs(closest -x))
            closest = *itr;
        return closest;
    }
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> seen(nums1.begin(), nums1.end());
        int maxDiff = INT_MIN, index = -1, actual_diff = -1;
        for(int i=0; i<nums2.size(); i++){
            int curr_closest = findClosest(seen, nums2[i]);
            int closest_diff = abs(curr_closest - nums2[i]), diff = abs(nums1[i] - nums2[i]);
            
            // cout << abs(diff - closest_diff) << " ";
            if(abs(diff - closest_diff) > maxDiff){
                maxDiff = abs(diff - closest_diff);
                actual_diff = abs(curr_closest - nums2[i]);
                index = i;
            }
        }
        
        // cout << index << endl;
        
        long ans = 0;
        for(int i=0; i<nums1.size(); i++){
            if(i == index)
                ans += actual_diff;
            else
                ans += abs(nums1[i] - nums2[i]);
        }
        return ans%1000'000'007;
    }
};