class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty())
            return (n==1 ? 1 : -1);
        
        int trustCount[n+1];
        memset(trustCount, 0, sizeof(trustCount));
        
        for(int i=0; i<(int)trust.size(); i++){
            // possibleJudge[trust[i][0]] = false;
            trustCount[trust[i][0]]--;
            trustCount[trust[i][1]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(trustCount[i] == n-1)
                return i;
        }
        
        return -1;
    }
};