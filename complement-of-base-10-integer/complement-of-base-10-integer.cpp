class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0)
            return 1;
        for(int i=0; i<31 && (1<<i)<=num; i++)
            num ^= (1<<i);
        return num;
    }
};