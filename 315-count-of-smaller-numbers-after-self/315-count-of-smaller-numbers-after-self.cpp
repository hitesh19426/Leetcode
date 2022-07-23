class BIT{
    vector<int> bit;
public:
    BIT(int n){
        bit.assign(n+1, 0);
    }
    
    int sum(int ind){
        int res = 0;
        for(++ind; ind>0; ind -= ind&-ind)
            res += bit[ind];
        return res;
    }
    
    int sum(int low, int high){
        return sum(high) - sum(low-1);
    }
    
    void update(int ind, int val = 1){
        for(++ind; ind<bit.size(); ind+=ind&-ind)
            bit[ind] += val;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n = 20'000, offset = 10'000;
        BIT bit(n);
        vector<int> ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--){
            ans[i] = bit.sum(0, nums[i]-1+offset);
            bit.update(nums[i]+offset);
        }
        return ans;
    }
};