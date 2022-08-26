class Solution {
    vector<int> powers;
public:
    Solution(){
        for(int i=0; i<31; i++)
            powers.push_back((1<<i));
    }
    
    bool convert(int n, int p){
        vector<int> ndigits(10, 0), pdigits(10, 0);
        while(n){
            ndigits[n%10]++;
            n /= 10;
        }
        while(p){
            pdigits[p%10]++;
            p /= 10;
        }
        return pdigits == ndigits;
    }
    
    bool reorderedPowerOf2(int n) {
        for(int i=0; i<31; i++){
            if(convert(n, powers[i]))
                return true;
        }
        return false;
    }
};