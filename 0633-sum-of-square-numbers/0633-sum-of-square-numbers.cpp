class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0; i*i<=c; i++){
            long long b = sqrt(c-i*i);
            if(b*b == c-i*i)
                return true;
        }
        return false;
    }
};