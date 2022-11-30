class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2005] = {}, unique = 0;
        for(int x: arr){
            if(count[x+1000]++ == 0)
                unique++;
        }
        
        unordered_set<int> umap;
        for(int i=0; i<=2002; i++){
            if(count[i])
                umap.insert(count[i]);
        }
        
        return umap.size() == unique;
    }
};