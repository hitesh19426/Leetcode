class Solution {
    int target, count = 0;
    vector<int> size, left, right;
	void make_set(int v){
        left[v] = right[v] = v;
		size[v] = 1;
        if(target == 1)
            count++;
	}
    
	void union_set(int a, int b){
        left[right[b]] = left[a];
        right[left[a]] = right[b];
        if(target == size[a])
            count--;
        if(target == size[b])
            count--;

        int total = size[a] + size[b];
        size[left[a]] = size[right[b]] = total;

        if(target == total)
            count++;
	}
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        target = m;
        vector<bool> seen(n, false);
        left.resize(n); right.resize(n); size.resize(n);
        
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