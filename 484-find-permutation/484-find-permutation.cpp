class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> permutation(s.size()+1);
        int lastI = -1;
        int curr = 1, ind = 0, n = s.size();
        while(ind <= n){
            if(ind == n || s[ind] == 'I'){
                permutation[ind] = curr++;
                for(int j=ind-1; j>lastI; j--)
                    permutation[j] = curr++;
                lastI = ind++;
            }else{
                ind++;
            }
        }
        return permutation;
    }
};