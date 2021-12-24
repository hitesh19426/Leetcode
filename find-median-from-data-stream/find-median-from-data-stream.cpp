class MedianFinder {
public:
    bool isEven = true;
    multiset<int> minset, maxset;
    MedianFinder() {}
    
    void addNum(int num) {
        isEven = !isEven;
        if(!isEven){
            if(maxset.empty() || num >= *minset.rbegin())
                maxset.insert(num);
            else{
                minset.insert(num);
                auto itr = minset.rbegin();
                maxset.insert(*itr);
                minset.erase(minset.find(*itr));
            }
        }
        else{
            if(num <= *maxset.begin()){
                minset.insert(num);
            }
            else{
                maxset.insert(num);
                auto itr = maxset.begin();
                minset.insert(*itr);
                maxset.erase(itr);
            }
        }
    }
    
    double findMedian() {
        if(!isEven){
            return (*maxset.begin());
        }
        return (*minset.rbegin() + *maxset.begin())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */