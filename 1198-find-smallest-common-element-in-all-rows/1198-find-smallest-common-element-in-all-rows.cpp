class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        const int maxn = 10005;
        int count[maxn] = {};
        for(auto &row: mat){
            for(auto &x: row)
                count[x]++;
        }
        
        for(int i=1; i<maxn; i++){
            if(count[i] == mat.size())
                return i;
        }
        
        return -1;
    }
};