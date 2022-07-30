class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        for(auto &str: words){
            if(str[0] == str[1])
                count[str[0]-'a'][str[1]-'a']++;
            else
                count[str[0]-'a'][str[1]-'a']++;
        }
        
        int ans = 0, max_equal = 0, hasodd = false;
        for(int i=0; i<26; i++){
            ans += (count[i][i]/2)*4;
            if(count[i][i]&1)
                hasodd = true;
            for(int j=i+1; j<26; j++)
                ans += min(count[i][j], count[j][i])*4;
        }
        
        ans += (hasodd ? 2 : 0);
        return ans;
    }
};