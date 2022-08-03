template<class T>
class DSU{
    unordered_map<T, T> parent;
    unordered_map<T, int> size;
public:
    DSU(){}
    
    T find_set(T v){
        if(parent.find(v) == parent.end())
            make_set(v);
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void make_set(T v){
        parent[v] = v;
        size[v] = 1;
    }
    
    void union_set(T a, T b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size())
            return false;
        
        DSU<string> dsu;
        for(auto &pairs: similarPairs){
            dsu.union_set(pairs[0], pairs[1]);
        }
        
        for(int i=0; i<sentence1.size(); i++){
            if(dsu.find_set(sentence1[i]) != dsu.find_set(sentence2[i]))
                return false;
        }
        
        return true;
    }
};