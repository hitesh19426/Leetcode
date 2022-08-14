class MinStack {
    long long globalMin = INT_MAX;
    stack<long long> stack;
public:
    MinStack() {}
    
    void push(int val) {
        if(val >= globalMin){
            stack.push(val);
        }else{
            stack.push(2*(long long)val - globalMin);
            globalMin = val;
        }
    }
    
    void pop() {
        if(stack.top() >= globalMin){
            stack.pop();
        }else{
            globalMin = 2*globalMin - stack.top();
            stack.pop();
        }
    }
    
    int top() {
        if(stack.top() >= globalMin){
            return stack.top();
        }else{
            return globalMin;
        }
    }
    
    int getMin() {
        return globalMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */