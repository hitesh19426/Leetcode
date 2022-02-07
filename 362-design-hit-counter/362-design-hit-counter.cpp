class HitCounter {
    int sum = 0;
    queue<pair<int,int>> hitwindow;
    
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front().first <= timestamp-300){
            sum -= hitwindow.front().second;
            hitwindow.pop();
        }
        
        if(hitwindow.empty() || hitwindow.back().first != timestamp){
            hitwindow.push({timestamp, 1});
        }
        else{
            hitwindow.back().second++;
        }
        sum++;
    }
    
    int getHits(int timestamp) {
        while(not hitwindow.empty() && hitwindow.front().first <= timestamp-300){
            sum -= hitwindow.front().second;
            hitwindow.pop();
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