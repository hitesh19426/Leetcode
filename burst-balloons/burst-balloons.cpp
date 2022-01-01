class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr{1};
        for(int x: nums){
            arr.push_back(x);
        }
        arr.push_back(1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int len=0; len<n; len++){
            for(int x=1, y=len+1; x<=n && y<=n; x++, y++){
                
                if(x == y){
                    dp[x][y] = arr[x-1]*arr[x]*arr[x+1];
                    continue;
                }
                
                for(int k=x; k<=y; k++)
                    dp[x][y] = max(dp[x][y], dp[x][k-1] + dp[k+1][y] + arr[x-1]*arr[k]*arr[y+1]);
                
            }
        }
        
        return dp[1][n];
        // return 0;
    }
};