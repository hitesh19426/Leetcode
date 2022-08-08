class DSU{
	vector<int> parent, size;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n), count(0) {
		for(int i=0; i<n; i++)
			make_set(i);
	}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
		count++;
	}

	int find_set(int v){
		if(v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	bool union_set(int a, int b){
		a = find_set(a);
		b = find_set(b);
		if(a != b){
			if(size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
			count--;
			return true;
		}
		return false;
	}
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU uf(n+1);
        for(int i=threshold+1; i<=n; i++){
            for(int j=i; j<=n; j+=i){
                uf.union_set(i, j);
            }
        }
        
        vector<bool> ans;
        for(auto &query: queries){
            ans.push_back(uf.find_set(query[0]) == uf.find_set(query[1]));
        }
        return ans;
    }
};