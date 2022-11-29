class RandomizedSet {
    unordered_map<int, int> pos;
    vector<int> set;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(pos.find(val) != pos.end())
            return false;
        set.push_back(val);
        pos[val] = set.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(pos.find(val) == pos.end())
            return false;
        int last = set.back();
        swap(set.back(), set[pos[val]]);
        pos[last] = pos[val];
        set.pop_back();
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        return set[rand()%set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */