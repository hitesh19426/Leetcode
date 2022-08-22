class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
            return false;
        int log2n = log2(n);
        return (log2n%2 == 0 && (1<<log2n) == n);
    }
};