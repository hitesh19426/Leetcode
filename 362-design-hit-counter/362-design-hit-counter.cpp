class HitCounter {
public:
    int sum = 0;
    queue<int> hitwindow;
    HitCounter() {}
    
    void hit(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front() <= timestamp-300){
            hitwindow.pop();
        }
        
        hitwindow.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front() <= timestamp-300)
            hitwindow.pop();
        return hitwindow.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */