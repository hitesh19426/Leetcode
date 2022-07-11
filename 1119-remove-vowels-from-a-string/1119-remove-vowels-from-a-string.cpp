class Solution {
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    string removeVowels(string s) {
        string ans = "";
        for(char c: s){
            if(!isvowel(c))
                ans += c;
        }
        return ans;
    }
};