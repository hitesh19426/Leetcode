class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int count1[1001] = {}, count2[1001] = {};
        for(int x: nums1)
            count1[x]++;
        for(int x: nums2)
            count2[x]++;
        
        vector<int> ans;
        for(int i=0; i<=1000; i++){
            int times = min(count1[i], count2[i]);
            for(int j=0; j<times; j++)
                ans.push_back(i);
        }
        return ans;
    }
};