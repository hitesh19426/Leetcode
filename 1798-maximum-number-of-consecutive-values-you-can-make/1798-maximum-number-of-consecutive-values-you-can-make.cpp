class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int target = 1;
        for(int x: coins){
            if(x > target)
                return target;
            target += x;
        }
        return target;
    }
};