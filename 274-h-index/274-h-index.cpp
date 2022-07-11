class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int res = 0, n = citations.size();
        for(int i=n-1; i>=0; i--){
            if(n-1-i >= citations[i])
                res = max(res, citations[i]);
            if(n-i <= citations[i])
                res = max(res, n-i);
        }
        return res;
    }
};