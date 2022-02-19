class MovingAverage {
public:
    int sum = 0, capacity;
    queue<int> queue;
    MovingAverage(int size) : capacity(size) {}
    
    double next(int val) {
        queue.push(val);
        sum += val;
        if(queue.size() > capacity){
            sum -= queue.front();
            queue.pop();
        }
        
        return (double)sum/queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */