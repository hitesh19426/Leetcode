class MyQueue {
    stack<int> stack1, stack2;
    
    void transferFrom1to2(){
        while(not stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
public:
    MyQueue() {}
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if(stack2.empty())
            transferFrom1to2();
        int x = stack2.top();
        stack2.pop();
        return x;
    }
    
    int peek() {
        if(stack2.empty())
            transferFrom1to2();
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */