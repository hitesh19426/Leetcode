class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> seld(n+1), held(n+1), reset(n+1);
        
        reset[0] = 0, seld[0] = INT_MIN, held[0] = INT_MIN;
        for(int i=1; i<=n; i++){
            reset[i] = max(reset[i-1], seld[i-1]);
            held[i] = max(held[i-1], reset[i-1] - prices[i-1]);
            seld[i] = held[i-1] + prices[i-1];
        }
        
        return max({reset.back(), seld.back(), held.back()});
        
    }
};