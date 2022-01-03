class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty())
            return (n==1 ? 1 : -1);
        
        bool possibleJudge[n+1];
        memset(possibleJudge, 1, sizeof(possibleJudge));
        for(int i=0; i<(int)trust.size(); i++){
            possibleJudge[trust[i][0]] = false;
        }
        
        for(int i=1; i<=n; i++){
            if(possibleJudge[i]){
                
                bool members[n+1];
                memset(members, 0, sizeof(members));
                
                int count = 0;
                for(int j=0; j<(int)trust.size(); j++){
                    if(trust[j][1] == i){
                        if(members[trust[j][0]] == false)
                            count++;
                        members[trust[j][0]] = true;
                    }
                }
                
                if(count == n-1){
                    return i;
                }
            }
        }
        
        return -1;
    }
};