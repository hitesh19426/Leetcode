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
    
    int get_size(int v){
        v = find_set(v);
        return size[v];
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        for(auto &edge: edges){
            uf.union_set(edge[0], edge[1]);
        }
        
        unordered_map<int, int> sizes;
        for(int i=0; i<n; i++){
            int v = uf.find_set(i);
            sizes[v] = uf.get_size(v);
        }
        
        long long count = 0, sum = 0;
        for(auto &[id, size]: sizes){
            count += sum*size;
            sum += size;
        }
        return count;
    }
};