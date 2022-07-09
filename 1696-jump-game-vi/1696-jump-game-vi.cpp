class Solution {
    void add(deque<int>& window, vector<int>& dp, int ind){
        while(!window.empty() && dp[ind] >= dp[window.front()])
            window.pop_front();
        window.push_front(ind);
    }
    
    int query(deque<int>& window, int ind, int right){
        while(!window.empty() && window.back() > right)
            window.pop_back();
        return window.back();
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        deque<int> window;
        vector<int> dp(n);
        
        add(window, dp, n-1);
        dp[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            int max_ind = query(window, i, min(n-1, i+k));
            dp[i] = dp[max_ind] + nums[i];
            add(window, dp, i);
        }
        
        return dp[0];
    }
};