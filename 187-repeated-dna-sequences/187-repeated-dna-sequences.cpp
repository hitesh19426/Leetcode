class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int p = 7, mod = 1e9+7, k = 10;
        
        vector<long long> powers(10, 1);
        for(int i=1; i<10; i++)
            powers[i] = (powers[i-1]*p)%mod;
        
        unordered_map<char, int> map{{'A',1},{'C',2},{'G',3},{'T',4}};
        
        long long hash = 0;
        for(int i=0; i<k; i++)
            hash = (hash+map[s[i]]*powers[k-1-i])%mod;
        
        unordered_set<int> seqs, repeated;
        vector<string> ans;
        for(int i=9, j=0; i<s.size(); i++, j++){
            if(j!=0){
                hash = ((hash - map[s[j-1]]*powers.back())*p + map[s[i]] + mod)%mod;
            }
            if(seqs.find(hash) != seqs.end()){
                if(repeated.find(hash) == repeated.end()){
                    repeated.insert(hash);
                    ans.push_back(s.substr(j, 10));
                }
            }
            seqs.insert(hash);
        }
        
        return ans;
    }
};