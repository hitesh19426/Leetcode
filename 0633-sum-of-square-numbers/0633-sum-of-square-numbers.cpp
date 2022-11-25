class Solution {
    vector<int> sq;
public:
    Solution(){
        const long long n = (1ll<<31ll)-1;
        for(long long i=0; i*i<=n; i++){
            sq.push_back(i*i);
        }
    }
    bool judgeSquareSum(int c) {
        for(int x: sq){
            if(binary_search(sq.begin(), sq.end(), c-x))
                return true;
        }
        return false;
    }
};