class Solution {
    unordered_map<int, int> helper(vector<vector<int>>& arrs, int low, int high){
        if(high < low)
            return unordered_map<int, int>();
        if(low == high){
            unordered_map<int, int> cnt;
            for(auto& x: arrs[low])
                cnt[x]++;
            return cnt;
        }
        
        int mid = (low+high)/2;
        auto left = helper(arrs, low, mid);
        auto right = helper(arrs, mid+1, high);
        
        unordered_map<int, int> cnt;
        for(auto &[key1, cnt1]: left){
            for(auto &[key2, cnt2]: right)
                cnt[key1+key2] += cnt1*cnt2;
        }
        return cnt;
    }
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> arrs{nums1, nums2, nums3, nums4};
        auto cnt = helper(arrs, 0, arrs.size()-1);
        return cnt[0];
    }
};
/*
TC(K, N) = logK*(time for merging = K*N * K*N) = K*K*N*N*logK
SC(K, N) = K*N
*/