class MyStack {
public:
    queue<int> queue1, queue2;
    MyStack() {}
    
    void push(int x) {
        while(not queue1.empty()){
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.push(x);
        while(not queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop();
        }
    }
    
    int pop() {
        if(queue1.empty())
            return -1;
        int x = queue1.front();
        queue1.pop();
        return x;
    }
    
    int top() {
        if(queue1.empty())
            return -1;
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */