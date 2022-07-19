struct trieNode{
    trieNode* nodes[26] = {};
    int sum = 0;
};

class trie{
    trieNode* root = new trieNode();
public:
    trie() {}
    void insert(string word, int val){
        auto ptr = root;
        for(char &c: word){
            int ind = c-'a';
            if(ptr->nodes[ind] == NULL)
                ptr->nodes[ind] = new trieNode();
            ptr->sum += val;
            ptr = ptr->nodes[ind];
        }
        ptr->sum += val;
    }
    
    int sum(string prefix){
        auto ptr = root;
        for(char &c: prefix){
            int ind = c-'a';
            if(ptr->nodes[ind] == NULL)
                return 0;
            ptr = ptr->nodes[ind];
        }
        return ptr->sum;
    }
};

class MapSum {
    trie *tr = new trie();
    unordered_map<string, int> value;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        if(value.find(key) == value.end())
            tr->insert(key, val);
        else
            tr->insert(key, val - value[key]);
        value[key] = val;
    }
    
    int sum(string prefix) {
        return tr->sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */