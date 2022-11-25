class Solution {
    set<long long> sq;
public:
    Solution(){
        const long long n = (1ll<<31ll)-1;
        for(long long i=0; i*i<=n; i++){
            sq.insert(i*i);
        }
    }
    bool judgeSquareSum(int c) {
        for(long long i=0; i*i<=c; i++){
            if(sq.find(c-i*i) != sq.end())
                return true;
        }
        return false;
    }
};