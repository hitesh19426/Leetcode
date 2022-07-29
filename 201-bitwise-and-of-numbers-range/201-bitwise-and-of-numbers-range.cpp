class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0, diff = right - left, andlr = left&right;
        for(int i=0; i<31; i++){
            bool bit3 = (diff <= (1<<i)-1);
            if(andlr&1 && (diff <= ((1<<i)-1)))
                ans |= (1<<i);
            andlr >>= 1;
        }
        return ans;
    }
};