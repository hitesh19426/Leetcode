class Solution {
public:
    int findComplement(int num) {
        for(int i=0; i<31 && (1<<i)<=num; i++)
            num ^= (1<<i);
        return num;
    }
};