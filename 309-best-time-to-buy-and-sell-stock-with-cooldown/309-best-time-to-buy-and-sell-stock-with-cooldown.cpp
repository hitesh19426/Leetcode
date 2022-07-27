class Solution {
    vector<int> dp;
    int helper(int ind, vector<int>& prices){
        if(ind >= prices.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = helper(ind+1, prices);
        for(int i=ind+1; i<prices.size(); i++)
            ans = max(ans, prices[i] - prices[ind] + helper(i+2, prices));
        return dp[ind] = ans;
        
        // if(last == -1)
        //     return dp[ind][last+1] = max(helper(ind+1, ind, prices), helper(ind+1, -1, prices));
        // return dp[ind][last+1] = max(prices[ind]-prices[last] + helper(ind+2, -1, prices), helper(ind+1, last, prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size()+1, -1);
        return helper(0, prices);
    }
};