class MedianFinder {
    bool isSizeOdd = false;
    priority_queue<int> minset;
    priority_queue<int, vector<int>, greater<int>> maxset;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(isSizeOdd){
            maxset.push(num);
            minset.push(maxset.top());
            maxset.pop();
        }else{
            minset.push(num);
            maxset.push(minset.top());
            minset.pop();
        }
        isSizeOdd = !isSizeOdd;
    }
    
    double findMedian() {
        if(isSizeOdd)
            return maxset.top();
        return (maxset.top()+minset.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */