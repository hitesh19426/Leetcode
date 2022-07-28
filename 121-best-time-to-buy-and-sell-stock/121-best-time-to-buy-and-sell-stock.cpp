class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int held[n+1], start = 0, finish[n+1];
        held[0] = INT_MIN, finish[0] = INT_MIN;
        
        for(int i=1; i<=n; i++){
            held[i] = max(held[i-1], start - prices[i-1]);
            finish[i] = max(finish[i-1], held[i-1] + prices[i-1]);
        }
        
        return max(finish[n], start);
    }
};