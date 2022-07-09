class Solution {
    vector<int> st;
    void update(int low, int high, int root, int ind, int new_val){
        if(ind < low || high < ind)
            return;
        if(low == high){
            st[root] = new_val;
            return;
        }
        int mid = low + (high-low)/2;
        update(low, mid, 2*root, ind, new_val);
        update(mid+1, high, 2*root+1, ind, new_val);
        st[root] = max(st[2*root], st[2*root+1]);
    }
    
    int query_max(int low, int high, int root, int a, int b){
        if(b < low || high < a)
            return INT_MIN;
        if(a <= low && high <= b)
            return st[root];
        int mid = low + (high-low)/2;
        auto left = query_max(low, mid, 2*root, a, b);
        auto right = query_max(mid+1, high, 2*root+1, a, b);
        return max(left, right);
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        st.assign(4*n, INT_MIN);
        
        dp[n-1] = nums[n-1];
        update(0, n-1, 1, n-1, dp[n-1]);
        for(int i=n-2; i>=0; i--){
            int left = i+1, right = min(n-1, i+k);
            int query_ans = query_max(0, n-1, 1, left, right);            
            dp[i] = query_ans + nums[i];
            update(0, n-1, 1, i, dp[i]);
        }
        
        return dp[0];
    }
};