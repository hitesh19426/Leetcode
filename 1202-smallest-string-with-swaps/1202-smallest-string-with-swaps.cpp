class DSU{
    vector<int> parent, size;
public:
    DSU(int n) : parent(n), size(n) {
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for(auto &pair: pairs)
            dsu.union_set(pair[0], pair[1]);
        
        unordered_map<int, string> groups;
        for(int i=0; i<n; i++)
            groups[dsu.find_set(i)] += s[i];
        for(auto &[root, group]: groups)
            sort(group.begin(), group.end(), greater<char>());
        
        string ans = "";
        for(int i=0; i<n; i++){
            string &group = groups[dsu.find_set(i)];
            ans += group.back();
            group.pop_back();
        }

        return ans;
    }
};