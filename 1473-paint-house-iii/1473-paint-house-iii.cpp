class Solution {
    vector<vector<vector<int>>> dp;
    int helper(int ind, int count, int prev, vector<int>& houses, vector<vector<int>>& cost, int& m, int& n, int& target){
        if(count > target || (ind == m && count < target))
            return 1e7;
        if(ind == m)
            return 0;
        if(dp[ind][count][prev] != -1)
            return dp[ind][count][prev];
        
        int min_cost = 1e7;
        if(houses[ind] != 0){
            bool changedNeighbor = (ind == 0 || houses[ind] != prev);
            min_cost = helper(ind+1, count + changedNeighbor, houses[ind], houses, cost, m, n, target);
        }
        else{
            for(int i=0; i<n; i++){
                bool changedNeighbor = (ind == 0 || i+1 != prev);
                int next = helper(ind+1, count + changedNeighbor, i+1, houses, cost, m, n, target);
                min_cost = min(min_cost, next + cost[ind][i]);
            }
        }
        return dp[ind][count][prev] = min_cost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int curr_cost = 0, min_cost = INT_MAX, count = 0;
        dp.assign(m, vector<vector<int>>(m, vector<int>(n+1, -1)));
        int ans = helper(0, count, 0, houses, cost, m, n, target);
        return (ans == 1e7 ? -1 : ans);
    }
};