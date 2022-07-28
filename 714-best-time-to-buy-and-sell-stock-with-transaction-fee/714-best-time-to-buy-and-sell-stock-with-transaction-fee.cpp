class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int reset_prev = 0, held_prev = INT_MIN;
        for(int i=1; i<=n; i++){
            int reset = max(reset_prev, held_prev + prices[i-1]);
            held_prev = max(held_prev, reset_prev - prices[i-1] - fee);
            reset_prev = reset;
        }
        return max(held_prev, reset_prev);
    }
};