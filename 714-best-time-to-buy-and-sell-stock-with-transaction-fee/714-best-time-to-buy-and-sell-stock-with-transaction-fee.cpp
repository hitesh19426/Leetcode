class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int reset[n+1], held[n+1];
        
        reset[0] = 0, held[0] = INT_MIN;
        for(int i=1; i<=n; i++){
            reset[i] = max(reset[i-1], held[i-1] + prices[i-1]);
            held[i] = max(held[i-1], reset[i] - prices[i-1] - fee);
        }
        return max(held[n], reset[n]);
    }
};