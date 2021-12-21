class Solution {
public:
    const static int offset = 1e4+1, sz = 1e5;
    int BIT[(int)1e5] = {0};
    
    int add(int n){
        int ans = 0;
        for(; n>0 ; n -= n&-n)
            ans += BIT[n];
        return ans;
    }
    
    void update(int index){
        for(; index < sz; index += index&-index)
            BIT[index]++;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int i=(int)nums.size()-1; i>=0; i--){
            update(nums[i]+offset);
            ans[i] = add(nums[i]+offset-1);
        }
        
        return ans;
    }
};