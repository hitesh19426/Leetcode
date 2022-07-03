class MedianFinder {
    bool isSizeOdd = false;
    priority_queue<int> higher;
    priority_queue<int, vector<int>, greater<int>> lower;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(isSizeOdd){
            higher.push(num);
            lower.push(higher.top());
            higher.pop();
        }
        else{
            lower.push(num);
            higher.push(lower.top());
            lower.pop();
        }
        isSizeOdd = !isSizeOdd;
    }
    
    double findMedian() {
        if(isSizeOdd&1)
            return higher.top();
        return (higher.top() + lower.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */