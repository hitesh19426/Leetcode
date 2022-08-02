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
        bool multi_parent = false, cycle = false;
        UnionFind uf(n+1);
        
        for(int i=0; i<n; i++){
            int par = edges[i][0], child = edges[i][1];
            // if parent exists, we do not enter second edge to union edge, so it does not count towards cycle
            if(parent[child] != -1){    // if parent already exists, store first and second edge
                multi_parent = true;
                first = {parent[child], child};
                second = {par, child};
            }
            else{
                // only add edge to uf if parent does not exists
                parent[child] = par;
                if(!uf.union_set(par, child)){
                    cycle = true;
                    last = {par, child};
                }
            }
        }
        
        if(multi_parent && cycle)   // case 3a
            return first;
        if(multi_parent)    // case 1 + case 3b
            return second;
        return last;    // case 2
    }
};
/*
case 1: backedge to different branch
case 2: backedge to root
case 3: backedge to ancestor other than parent ->     
    a) edge to be removed is inserted first
    b) edge to be removed is inserted later
*/
/*
TC(N) = O(N*alpha(N)) on avg, O(N*logN) in worst case
SC(N) = O(N)
*/