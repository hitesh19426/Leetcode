class LFUCache {
    int sz = 0, cap;
    unordered_map<int, int> value;  // key -> value
    unordered_map<int, int> counter;    // key -> counter
    unordered_map<int, list<int>::iterator> pos;   // key -> pos
    unordered_map<int, list<list<int>>::iterator> buckets;  // counter -> bucket
    list<list<int>> cache;    // actual buckets
public:
    LFUCache(int capacity) : cap(capacity) {}
    
    void moveKey(int key){
        // find bucket of key and remove key from that bucket
        int count = counter[key];
        buckets[count]->erase(pos[key]);
        
        // insert next container if it does not exists
        if(buckets.find(count+1) == buckets.end()){
            cache.insert(next(buckets[count]), list<int>());
            buckets[count+1] = next(buckets[count]);
        }
        
        // remove current bucket if empty
        if(buckets[count]->empty()){
            cache.erase(buckets[count]);
            buckets.erase(count);
        }
        
        // increase counter
        count = ++counter[key];
        
        // insert key in new counter container
        buckets[count]->push_front(key);
        pos[key] = buckets[count]->begin();
    }
    
    int get(int key) {
        // key does not exist
        if(counter.find(key) == counter.end())
            return -1;
        
        // move key from current bucket to next bucket
        moveKey(key);
        
        // return value of key
        return value[key];
    }
    
    void put(int key, int val) {
        if(cap == 0)
            return;
        
        if(counter.find(key) == counter.end()){
            // invalidate key
            if(sz == cap){
                // remove least recent from least frequent
                auto& firstbucket = cache.front();
                int removedKey = firstbucket.back();
                firstbucket.pop_back();

                // update parameter of key
                if(firstbucket.empty()){
                    cache.pop_front();
                    buckets.erase(counter[removedKey]);
                }

                counter.erase(removedKey);
                value.erase(removedKey);
                pos.erase(removedKey);
                sz--;
            }
            
            // insert bucket 1 if it does not exist
            if(buckets.find(1) == buckets.end()){
                cache.insert(cache.begin(), list<int>());
                buckets[1] = cache.begin();
            }
            
            // update values/quantities for current key
            buckets[1]->push_front(key);
            pos[key] = buckets[1]->begin();
            counter[key] = 1;
            value[key] = val;
            sz++;
        }
        else{
            // move key and update its value
            moveKey(key);
            value[key] = val;
            // sz++;
        }
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */