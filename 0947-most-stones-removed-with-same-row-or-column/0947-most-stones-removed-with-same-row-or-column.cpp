class DSU{
    vector<int> parent, size;
public:
    int count = 0;
    DSU(int n) : parent(n), size(n){
        for(int i=0; i<n; i++)
            make_set(i);
    }
    
    void make_set(int v){
        size[v] = 0;
        parent[v] = v;
        count++;
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
    int removeStones(vector<vector<int>>& stones) {
        vector<int> rows(10001, -1), cols(10001, -1);
        DSU uf(stones.size());
        
        for(int i=0; i<stones.size(); i++){
            if(rows[stones[i][0]] == -1)
                rows[stones[i][0]] = i;
            else
                uf.union_set(rows[stones[i][0]], i);
            
            if(cols[stones[i][1]] == -1)
                cols[stones[i][1]] = i;
            else
                uf.union_set(cols[stones[i][1]], i);
        }
        
        return stones.size() - uf.count;
    }
};