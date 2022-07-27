class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> seld(n+1), held(n+1), reset(n+1);
        
        // reset[0] = 0, seld[0] = INT_MIN, held[0] = INT_MIN;
        int reset_prev = 0, seld_prev = INT_MIN, held_prev = INT_MIN;
        for(int i=0; i<n; i++){
            // reset[i] = max(reset[i-1], seld[i-1]);
            // held[i] = max(held[i-1], reset[i-1] - prices[i-1]);
            // seld[i] = held[i-1] + prices[i-1];
            int reset = max(reset_prev, seld_prev);
            int held = max(held_prev, reset_prev - prices[i]);
            int seld = held_prev + prices[i];
            
            reset_prev = reset, held_prev = held, seld_prev = seld;
        }
        
        return max({reset_prev, seld_prev, held_prev});
        
    }
};