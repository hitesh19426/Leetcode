class UnionFind{
    vector<int> parent, size;
public:
    UnionFind(int n) : parent(n), size(n) {
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
    
    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b)
            return false;
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1), first, second, last;
        // int first = -1, second = -1, last = -1;
        bool multi_parent = false, cycle = false;
        UnionFind uf(n+1);
        
        for(int i=0; i<n; i++){
            int par = edges[i][0], child = edges[i][1];
            if(parent[child] != -1){    // if parent already exists, store first and second edge
                multi_parent = true;
                first = {parent[child], child};
                second = {par, child};
            }
            else{
                parent[child] = par;
                if(!uf.union_set(par, child)){
                    cycle = true;
                    last = {par, child};
                }
            }
        }
        
        if(multi_parent && cycle)
            return first;
        if(multi_parent)
            return second;
        return last;
    }
};