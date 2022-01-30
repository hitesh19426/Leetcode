class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> umap;
        for(auto x:deck)
            umap[x]++;
        int current = umap[deck[0]];
        for(auto pa: umap){
            current = __gcd(current, pa.second);
        }
        return current>1;
    }
};