class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(costs[0]);
        
        for(int i=1; i<costs.size(); i++){
            vector<int> curr(3);
            for(int j=0; j<3; j++){
                curr[j] = min(dp[(j+1)%3], dp[(j+2)%3]) + costs[i][j];
            }
            dp = curr;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};