class HitCounter {
public:
    int sum = 0;
    deque<int> hitwindow;
    HitCounter() {
        hitwindow.clear();
    }
    
    void hit(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front() <= timestamp-300){
            hitwindow.pop_front();
            sum--;
        }
        
        hitwindow.push_back(timestamp);
        sum++;
    }
    
    int getHits(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front() <= timestamp-300){
            hitwindow.pop_front();
            sum--;
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */