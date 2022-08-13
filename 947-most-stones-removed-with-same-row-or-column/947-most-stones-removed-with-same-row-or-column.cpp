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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), count = 0;
        vector<int> row(10001, -1), col(10001, -1);
        DSU uf(n);
        
        for(int i=0; i<stones.size(); i++){
            if(row[stones[i][0]] != -1)
                uf.union_set(row[stones[i][0]], i);
            if(col[stones[i][1]] != -1)
                uf.union_set(col[stones[i][1]], i);
            row[stones[i][0]] = i;
            col[stones[i][1]] = i;
        }
        return stones.size() - uf.count;
    }
};