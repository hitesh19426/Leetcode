class DSU{
    int count = 0;
    vector<int> parent, size, minvalue;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        minvalue.resize(n);
        for(int i=0; i<n; i++)
            make_set(i);
    }
    
    int find_set(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
        minvalue[v] = v;
        count++;
    }
    
    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b)
            return false;
        
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        minvalue[a] = min(minvalue[a], minvalue[b]);
        count--;
        return true;
    }
    
    int get_count(){
        return count;
    }
    
    char find_smallest(int v){
        v = find_set(v);
        return 'a' + minvalue[v];
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0; i<s1.size(); i++)
            dsu.union_set(s1[i]-'a', s2[i]-'a');
        
        for(char &c: baseStr)
            c = dsu.find_smallest(c-'a');
        return baseStr;
    }
};