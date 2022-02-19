class MovingAverage {
public:
    int sum = 0, size = 0, capacity, insert_index = 0;
    vector<int> window;
    MovingAverage(int size) : capacity(size) {
        window.assign(size, 0);
    }
    
    double next(int val) {
        sum -= window[insert_index%(window.size())];
        sum += (window[insert_index%(window.size())] = val);
        
        insert_index = (++insert_index)%(window.size());
        if(size < window.size())
            size++;
        
        return (double)sum/size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */