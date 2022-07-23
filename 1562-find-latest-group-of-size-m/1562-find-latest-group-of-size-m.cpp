class Solution {
    vector<int> parent, size, sizes;
	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
        sizes[1]++;
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
			
            sizes[size[a]]--;
            sizes[size[b]]--;
            
            parent[b] = a;
            size[a] += size[b];
            sizes[size[a]]++;
		}
	}
    
    bool find_size(int m){
        return sizes[m];
    }
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        parent.assign(n, -1);
        size.assign(n, 0);
        sizes.assign(n+1, 0);
        
        int i = 0, ans = -1;
        for(int x: arr){
            x--;
            make_set(x);
            
            if(x-1>=0 && parent[x-1] != -1)
                union_set(x-1, x);
            if(x+1<arr.size() && parent[x+1] != -1)
                union_set(x+1, x);
            if(find_size(m))
                ans = max(ans, i+1);
            i++;
        }
        
        return ans;
    }
};
/*
TC(N, M) = O(N*alpha(N))
SC(N, M) = O(N)
*/