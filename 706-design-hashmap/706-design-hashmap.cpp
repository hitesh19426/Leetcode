class Node{
public:
    int key, value;
    Node(int key, int value) : key(key), value(value) {}
};

class MyHashMap {
    const int mod, p;
    vector<list<Node>> buckets;
public:
    MyHashMap() : mod(1007), p(997) {
        buckets.assign(mod, list<Node>());
    }
    
    void put(int key, int value) {
        int hash = key*p % mod;
        auto &bucket = buckets[hash];
        for(auto itr = bucket.begin(); itr != bucket.end(); itr++){
            if(itr->key == key){
                itr->value = value;
                return;
            }
        }
        
        buckets[hash].push_back(Node(key, value));
    }
    
    int get(int key) {
        int hash = key*p % mod;
        auto &bucket = buckets[hash];
        for(auto itr = bucket.begin(); itr != bucket.end(); itr++){
           if(itr->key == key){
                return itr->value;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = key*p % mod;
        auto &bucket = buckets[hash];
        for(auto itr = bucket.begin(); itr != bucket.end(); itr++){
           if(itr->key == key){
                buckets[hash].erase(itr);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */