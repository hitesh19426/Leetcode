class MedianFinder {
public:
    bool isEven = true;
    // multiset<int> minset, maxset;
    priority_queue<int> minset;
    priority_queue<int, vector<int>, greater<int>> maxset;
    MedianFinder() {}
    
    void addNum(int num) {
        isEven = !isEven;
        if(!isEven){
            if(maxset.empty() || num >= minset.top())
                maxset.push(num);
            else{
                minset.push(num);
                maxset.push(minset.top());
                minset.pop();
            }
        }
        else{
            if(num <= maxset.top()){
                minset.push(num);
            }
            else{
                maxset.push(num);
                minset.push(maxset.top());
                maxset.pop();
            }
        }
    }
    
    double findMedian() {
        if(!isEven){
            return (maxset.top());
        }
        return (minset.top() + maxset.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */