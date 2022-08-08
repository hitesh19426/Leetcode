class DSU{
    vector<int> parent, size;
public:
    int count;
    
    DSU(int n) : parent(n), size(n), count(0) {
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
    static bool comparator(const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0; i<queries.size(); i++)
            queries[i].push_back(i);
        
        sort(edgeList.begin(), edgeList.end(), comparator);    
        sort(queries.begin(), queries.end(), comparator);
        
        int edge = 0;
        DSU dsu(n);
        vector<bool> ans(queries.size());
        
        for(auto &query: queries){
            while(edge < edgeList.size() && edgeList[edge][2] < query[2]){
                dsu.union_set(edgeList[edge][0], edgeList[edge][1]);
                edge++;
            }
            
            ans[query[3]] = dsu.find_set(query[0]) == dsu.find_set(query[1]);
        }
        
        return ans;
    }
};