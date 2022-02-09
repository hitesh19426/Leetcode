class Solution {
public:
    int ans = 0;
    int findLength(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size(), ans =0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(arr1[i-1] == arr2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        
        // solve(arr1, arr2, arr1.size()-1, arr2.size()-1);
        return ans;
    }
};

/*
Let us say arr1 is always smaller.

Brute Force -- Iterate over all subarray of arr1 and check if it exists in arr2.

We will have m^2 subarray from arr1, and to check for same subarray in arr2, we will iterate all subarray of that particular length, which is n^2.

So total complexity = m^2 * n^2

Optimzed - Use rolling hash -- the string hashing technique.

With rolling hash, we can check if a particular subarray exists in arr2 in O(n) time. O(n) because we will still have to iterate over all arrays of that length.

Small optimizations: Once you have found a array of particular length, no need to look for more subarray of that length. Deal with equal array at the start only.

*/