class DSU{
    set<int> groups;
	vector<int> parent, size, start;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n), start(n) {}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
        start[v] = v;
        groups.insert(v);
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
            start[a] = min(start[a], start[b]);
            groups.erase(b);
		}
	}
    
    vector<vector<int>> get_intervals(){
        vector<vector<int>> ans;
        for(auto& v: groups)
            ans.push_back({start[v], start[v]+size[v]-1});
        return ans;
    }
};

class SummaryRanges {
    int n;
    DSU uf;
    vector<bool> seen;
public:
    SummaryRanges() : n(10001), uf(n+1), seen(n+1) {}
    
    void addNum(int val) {
        if(seen[val])
            return;
        seen[val] = true;
        uf.make_set(val);
        if(val>0 && seen[val-1])
            uf.union_set(val, val-1);
        if(val+1<=n && seen[val+1])
            uf.union_set(val, val+1);
    }
    
    vector<vector<int>> getIntervals() {
        return uf.get_intervals();
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */