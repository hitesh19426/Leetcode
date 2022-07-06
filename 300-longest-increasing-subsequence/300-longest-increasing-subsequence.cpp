class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int x: nums){
            if(lis.empty() || lis.back() < x)
                lis.push_back(x);
            else{
                auto itr = lower_bound(lis.begin(), lis.end(), x);
                *itr = x;
            }
        }
        return lis.size();
    }
};