class TimeMap {
    map<int, int, greater<int>> position;
    vector<pair<string, string>> timemap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        position[timestamp] = timemap.size();
        timemap.push_back({key, value});
    }
    
    string get(string key, int timestamp) {
        auto itr = position.lower_bound(timestamp);
        if(itr == position.end() )
            return "";
        int index = itr->second;
        while(index>=0){
            if(timemap[index].first == key)
                return timemap[index].second;
            index--;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/*

TimeStamps = 1, 2, 3, ..., 10^7
             KV,KV,KV,..., KV

set() - insert key, value at t = timestamp.
get() - search till timestamp, whenever you see key, store its value, return this value

set() - O(1)
get() - O(N = 10^7)






*/