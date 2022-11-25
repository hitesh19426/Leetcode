class Solution {
    unordered_set<long long> sq;
public:
    Solution(){
        const long long n = (1ll<<31ll)-1;
        for(long long i=0; i*i<=n; i++){
            sq.insert(i*i);
        }
    }
    bool judgeSquareSum(int c) {
        for(int x: sq){
            if(sq.find(c-x) != sq.end())
                return true;
        }
        return false;
    }
};