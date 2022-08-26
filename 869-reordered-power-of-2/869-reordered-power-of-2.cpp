class Solution {
public:
    bool convert(int n, int p){
        int ndigits[10] = {}, pdigits[10] = {};
        while(n){
            ndigits[n%10]++, n /= 10;
        }
        while(p){
            pdigits[p%10]++, p /= 10;
        }
        for(int i=0; i<10; i++){
            if(pdigits[i] != ndigits[i])
                return false;
        }
        return true;
    }
    
    bool reorderedPowerOf2(int n) {
        for(int i=0; i<31; i++){
            if(convert(n, (1<<i) ))
                return true;
        }
        return false;
    }
};