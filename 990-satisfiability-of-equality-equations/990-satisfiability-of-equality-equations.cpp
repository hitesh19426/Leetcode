class DSU{
    int count = 0;
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
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
        count--;
        return true;
    }
    
    int get_count(){
        return count;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        partition(equations.begin(), equations.end(), [](auto &a) -> bool {
            return a[1] == '=';
        });
        
        DSU dsu(26);
        for(auto eq: equations){
            if(eq[1] == '!'){
                if(dsu.find_set(eq[0]-'a') == dsu.find_set(eq[3]-'a'))
                    return false;
            }
            else
                dsu.union_set(eq[0]-'a', eq[3]-'a');
        }
        
        return true;
    }
};