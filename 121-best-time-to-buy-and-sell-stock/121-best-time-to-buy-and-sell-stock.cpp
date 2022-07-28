class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int held[n+1], start[n+1], finish[n+1];
        held[0] = INT_MIN, start[0] = 0, finish[0] = INT_MIN;
        
        for(int i=1; i<=n; i++){
            start[i] = start[i-1];
            held[i] = max(held[i-1], start[i-1] - prices[i-1]);
            finish[i] = max(finish[i-1], held[i-1] + prices[i-1]);
        }
        
        return max(finish[n], start[n]);
    }
};