class Solution {
    int dp[100][100][21] = {};
    const int INF = 1000'000'0;
    
    int helper(int ind, int count, int prev, vector<int>& houses, vector<vector<int>>& cost, int& m, int& n, int& target){
        if(count > target || (ind == m && count < target))
            return INF;
        if(ind == m)
            return 0;
        if(dp[ind][count][prev])
            return dp[ind][count][prev];
        
        int min_cost = INF;
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
        int ans = helper(0, 0, 0, houses, cost, m, n, target);
        return (ans == INF ? -1 : ans);
    }
};