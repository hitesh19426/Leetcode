class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> size(n+2, 0);
        
        int ans = -1, step = 1, count = 0;
        for(int x: arr){
            int left = x - size[x-1], right = x + size[x+1];
            count -= ((size[left] == m) + (size[right] == m)); 
            size[left] = size[right] = size[x] = size[left] + size[right] + 1;
            count += (size[x] == m);
            if(count)
                ans = max(ans, step);
            step++;
        }
        
        return ans;
    }
};
/*
TC(N, M) = O(N))
SC(N, M) = O(N)
*/