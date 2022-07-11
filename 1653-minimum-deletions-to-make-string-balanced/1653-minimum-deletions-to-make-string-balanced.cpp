class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0, b = 0, res = INT_MAX;
        for(int i=0; i<s.size(); i++)
            a += (s[i] == 'a');
        
        res = a;
        for(int i=0; i<s.size(); i++){
            b += (s[i] == 'b'), a -= (s[i] == 'a');
            res = min(res, b + a);
        }
        res = min(res, b);
        
        return res;
    }
};