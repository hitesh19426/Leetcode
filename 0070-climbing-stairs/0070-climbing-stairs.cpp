class Solution {
public:
    int climbStairs(int n) {
        int oneBack = 1, twoBack = 1, curr = 1;
        for(int i=2; i<=n; i++){
            curr = oneBack + twoBack;
            twoBack = oneBack;
            oneBack = curr;
        }
        return curr;
    }
};