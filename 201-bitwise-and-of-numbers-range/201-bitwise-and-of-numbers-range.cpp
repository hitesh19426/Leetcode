class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0, diff = right - left;
        for(int i=0; i<31; i++){
            bool bit1 = left&1, bit2 = right&1, bit3 = (diff <= (1<<i)-1);
            if(bit1 && bit2 && bit3)
                ans |= (1<<i);
            left >>= 1, right >>= 1;
        }
        return ans;
    }
};