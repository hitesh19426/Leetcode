class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int held[n+1], reset[n+1];
        held[0] = INT_MIN, reset[0] = 0;
        
        for(int i=1; i<=n; i++){
            reset[i] = max(reset[i-1], held[i-1] + prices[i-1]);
            held[i] = max({held[i-1], reset[i-1] - prices[i-1]});
        }
        return max(held[n], reset[n]);
    }
};