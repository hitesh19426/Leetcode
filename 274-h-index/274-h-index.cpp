class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        int ind = 1, n = citations.size();
        while(ind<=n && citations[ind-1] >= ind){
            ind++;
        }
        return --ind;
    }
};