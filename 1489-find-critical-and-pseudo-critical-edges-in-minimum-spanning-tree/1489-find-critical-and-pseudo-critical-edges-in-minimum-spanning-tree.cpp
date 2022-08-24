class DSU{
	vector<int> parent, size;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n) {
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) -> bool {
            return a[2] < b[2];
        });
        
        int originalMST = findMST(n, edges);
        
        vector<int> critical, pseudo;
        for(int i=0; i<edges.size(); i++){
            if(findMST(n, edges, i, -1) > originalMST)
                critical.push_back(edges[i][3]);
            else if(findMST(n, edges, -1, i) == originalMST)
                pseudo.push_back(edges[i][3]);
        }
        
        
        return {critical, pseudo};
    }
    
    int findMST(int n, vector<vector<int>>& edges, int exclude = -1, int include = -1){
        DSU uf(n);
        int cost = 0;
        
        if(include != -1){
            uf.union_set(edges[include][0], edges[include][1]);
            cost += edges[include][2];
        }
        
        for(int i=0; i<edges.size(); i++){
            if(i == exclude || i == include)
                continue;
            if(uf.union_set(edges[i][0], edges[i][1]))
                cost += edges[i][2];
        }
        
        return (uf.count != 1 ? INT_MAX : cost);
    }
};