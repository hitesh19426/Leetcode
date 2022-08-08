class DSU{
	vector<int> parent, size;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n), count(0) {}

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
    int id(int x, int y, int n){
        return x*n + y;
    }
    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> dir{1, 0, -1, 0, 1};
        
        vector<int> ans;
        DSU uf(m*n);
        for(auto &pos: positions){
            int x = pos[0], y = pos[1];
            if(grid[x][y] == 0){
                uf.make_set(id(x, y, n));
                for(int k=0; k<4; k++){
                    int newx = x+dir[k], newy = y+dir[k+1];
                    if(isvalid(newx, newy, m, n) && grid[newx][newy] == 1)
                        uf.union_set(id(newx, newy, n), id(x, y, n));
                }
                grid[x][y] = 1;
            }
            
            ans.push_back(uf.count);
        }
        
        return ans;
    }
};
/*
TC(M,N,Q) = Q*log(MN)
SC(M,N,Q) = M*N
*/