class DSU{
    vector<int> parent, size;
public:
    int count = 0;
    
    DSU(int n) : parent(n), size(n), count(n) {
        for(int i=0; i<n; i++)
            make_set(i);
    }
    
    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
    }
    
    int find_set(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            count--;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &edge: edges)
            dsu.union_set(edge[0], edge[1]);
        return dsu.count;
    }
};