class Solution {
    int countDistinct(int arr[26]){
        int res = 0;
        for(int i=0; i<26; i++)
            res += (arr[i] != 0);
        return res;
    }
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> suffix(n);
        
        vector<int> count(26, 0);
        for(int i=s.size()-1, unique = 0; i>=0; i--){
            if(count[s[i]-'a']++ == 0)
                suffix[i] = ++unique;
            else
                suffix[i] = unique;
        }
        
        int ans = 0;
        fill(count.begin(), count.end(), 0);
        for(int i=0, unique = 0; i<s.size()-1; i++){
            if(count[s[i]-'a']++ == 0)
                ++unique;
            if(unique == suffix[i+1])
                ans++;
        }
        return ans;
    }
};
/*
T(N) = O(26*N)
S(N) = O(N)
*/