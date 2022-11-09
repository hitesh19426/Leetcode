class StockSpanner {
    int ind = 0;
    stack<pair<int, int>> stack;
public:
    StockSpanner() {
        while(!stack.empty())
            stack.pop();
    }
    
    int next(int price) {
        while(!stack.empty() && stack.top().first <= price)
            stack.pop();
        int ans = (stack.empty() ? ind+1 : ind-stack.top().second);
        stack.push({price, ind++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */