class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i=0; i<31; i++){
            bool bit1 = left&(1<<i), bit2 = right&(1<<i), bit3 = (right - left <= (1<<i)-1);
            if(bit1 && bit2 && bit3)
                ans |= (1<<i);
        }
        return ans;
    }
};