class MyStack {
public:
    queue<int> queue1, queue2, queue;
    MyStack() {}
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        if(queue.empty())
            return -1;
        int n = queue.size()-1;
        while(n--){
            queue.push(queue.front());
            queue.pop();
        }
        int x = queue.front();
        queue.pop();
        return x;
    }
    
    int top() {
        if(queue.empty())
            return -1;
        int n = queue.size(), last = -1;
        while(n--){
            last = queue.front();
            queue.push(last);
            queue.pop();
        }
        return last;
    }
    
    bool empty() {
        return queue.empty();
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