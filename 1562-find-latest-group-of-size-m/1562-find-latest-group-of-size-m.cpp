class Solution {
    int target, count = 0;
    vector<int> parent, size, left, right;
	void make_set(int v){
		// parent[v] = v;
        left[v] = right[v] = v;
		size[v] = 1;
        if(target == 1)
            count++;
	}

	// int find_set(int v){
	// 	if(v == parent[v])
	// 		return v;
	// 	return parent[v] = find_set(parent[v]);
	// }

	void union_set(int a, int b){
		// a = find_set(a);
		// b = find_set(b);
        // left[b] = left[a];
        // right[a] = b;
        
        // if(size[a] < size[b])
        //     swap(a, b);
        
        left[right[b]] = left[a];
        right[left[a]] = right[b];
        if(target == size[a])
            count--;
        if(target == size[b])
            count--;

        // parent[b] = a;
        int total = size[a] + size[b];
        size[left[a]] = size[right[b]] = total;
        // size[left[a]] += size[b];

        if(target == total)
            count++;
	}
    
    bool find_size(){
        return count;
    }
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        target = m;
        vector<bool> seen(n, false);
        left.assign(n, -1); right.assign(n, -1);
        size.assign(n, 0);
        
        int i = 0, ans = -1;
        for(int x: arr){
            x--;
            seen[x] = true;
            make_set(x);
            
            
            if(x-1>=0 && seen[x-1])
                union_set(x-1, x);
            if(x+1<arr.size() && seen[x+1])
                union_set(x, x+1);
            if(count)
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