class TimeMap {
    map<string, vector<pair<int, string>>> position;   // strings, vector of timestamp, value
    // vector<pair<string, string>> timemap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        position[key].push_back({timestamp, value});
        // timemap.push_back({key, value});
    }
    
    string get(string key, int timestamp) {
        auto &positions = position[key];
        int low = 0, high = positions.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(positions[mid].first <= timestamp)
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        
        return (ans == -1 ? "" : positions[ans].second);
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