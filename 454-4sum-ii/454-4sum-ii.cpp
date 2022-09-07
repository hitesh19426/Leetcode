class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> sum12, sum34;
        for(int& x: nums1){
            for(int &y: nums2)
                sum12[x+y]++;
        }
        
        for(int& x: nums3){
            for(int &y: nums4){
                sum34[x+y]++;
            }
        }
        
        int ans = 0;
        for(auto &[key, cnt]: sum12){
            if(sum34.find(-key) != sum34.end())
                ans += cnt*sum34[-key];
        }
        
        return ans;
    }
};