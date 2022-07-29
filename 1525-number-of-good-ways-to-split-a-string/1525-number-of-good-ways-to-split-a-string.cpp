class Solution {
    int countDistinct(int arr[26]){
        int res = 0;
        for(int i=0; i<26; i++)
            res += (arr[i] != 0);
        return res;
    }
public:
    int numSplits(string s) {
        int count[26] = {};
        for(int i=0; i<s.size(); i++)
            count[s[i]-'a']++;
        
        int prefix[26] = {}, ans = 0;
        for(int i=0; i<s.size()-1; i++){
            count[s[i]-'a']--;
            prefix[s[i]-'a']++;
            if(countDistinct(count) == countDistinct(prefix))
                ans++;
        }
        return ans;
    }
};