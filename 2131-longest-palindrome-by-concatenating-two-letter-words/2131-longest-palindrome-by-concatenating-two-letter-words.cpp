class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        for(auto &word: words){
            count[word[0]-'a'][word[1]-'a']++;
        }
        
        int ans = 0, rem = false;
        for(int i=0; i<26; i++){
            ans += (count[i][i]/2)*4;
            rem |= count[i][i]&1;
        }
        
        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                ans += 4*min(count[i][j], count[j][i]);
            }
        }
        
        return (rem ? ans+2 : ans);
    }
};