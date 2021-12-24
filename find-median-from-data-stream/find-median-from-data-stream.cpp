class MedianFinder {
public:
    int count = 0;
    multiset<int> minset, maxset;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;
        if(count&1){
            if(maxset.empty() || num >= *minset.rbegin())
                maxset.insert(num);
            else{
                minset.insert(num);
                maxset.insert(*minset.rbegin());
                minset.erase(minset.find(*minset.rbegin()));
            }
        }
        else{
            if(num <= *maxset.begin()){
                minset.insert(num);
            }
            else{
                maxset.insert(num);
                minset.insert(*maxset.begin());
                maxset.erase(maxset.begin());
            }
        }
        
//         minset.insert(num);
//         if(minset.size() > maxset.size()){
//             maxset.insert(*minset.rbegin());
//             minset.erase(minset.find(*minset.rbegin()));
//         }
    }
    
    double findMedian() {
        if(count&1){
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