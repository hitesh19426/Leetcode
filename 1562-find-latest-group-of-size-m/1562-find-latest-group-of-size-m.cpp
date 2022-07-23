class DSU{
    multiset<int> sizes;
    vector<int> parent, size;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n), count(0) {}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
		count++;
        sizes.insert(1);
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
			
            sizes.erase(sizes.find(size[a]));
            sizes.erase(sizes.find(size[b]));
            
            parent[b] = a;
            size[a] += size[b];
			count--;
            
            sizes.insert(size[a]);
			return true;
		}
		return false;
	}
    
    bool find_size(int m){
        return sizes.find(m) != sizes.end();
    }
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        DSU uf(arr.size());
        vector<bool> seen(arr.size(), false);
        
        int i = 0, ans = -1;
        for(int x: arr){
            x--;
            uf.make_set(x);
            seen[x] = true;
            
            if(x-1>=0 && seen[x-1])
                uf.union_set(x-1, x);
            if(x+1<arr.size() && seen[x+1])
                uf.union_set(x+1, x);
            if(uf.find_size(m))
                ans = max(ans, i+1);
            i++;
        }
        
        return ans;
    }
};
/*
TC(N, M) = O(N*log(N))
SC(N, M) = O(N)
*/