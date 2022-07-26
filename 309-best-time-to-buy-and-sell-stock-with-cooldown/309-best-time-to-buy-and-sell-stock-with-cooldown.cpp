class Solution {
    vector<vector<int>> dp;
    int helper(int ind, int last, vector<int>& prices){
        if(ind >= prices.size())
            return 0;
        if(dp[ind][last+1] != -1)
            return dp[ind][last+1];
        
        if(last == -1)
            return dp[ind][last+1] = max(helper(ind+1, ind, prices), helper(ind+1, -1, prices));
        return dp[ind][last+1] = max(prices[ind]-prices[last] + helper(ind+2, -1, prices), helper(ind+1, last, prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(prices.size()+1, -1));
        return helper(0, -1, prices);
    }
};