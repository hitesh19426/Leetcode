class DSU{
    vector<int> parent, size;
public:
    DSU(int n) : parent(n), size(n) {
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
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        partition(equations.begin(), equations.end(), [](auto &a) -> bool {
            return a[1] == '=';
        });
        
        DSU uf(26);
        for(auto& eq: equations){
            if(eq[1] == '='){
                uf.union_set(eq[0]-'a', eq[3]-'a');
            }else{
                if(uf.find_set(eq[0]-'a') == uf.find_set(eq[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};