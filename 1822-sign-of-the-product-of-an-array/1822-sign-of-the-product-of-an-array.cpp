class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg = false;
        for(int x: nums){
            if(x == 0)
                return 0;
            if(x < 0)
                neg = !neg;
        }
        return (neg ? -1 : 1);
    }
};