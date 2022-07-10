class Solution {
    vector<int> dp;
    int helper(int ind, vector<int>& cost){
        if(ind >= cost.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        return dp[ind] = min(cost[ind]+helper(ind+1, cost), cost[ind]+helper(ind+2, cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n, -1);
        return min(helper(0, cost), helper(1, cost));
    }
};