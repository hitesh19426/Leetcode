class Solution {
    const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string getCode(string &word){
        string code = "";
        for(auto &c: word)
            code += morse[c-'a'];
        return code;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes;
        for(auto &word: words)
            codes.push_back(getCode(word));
        unordered_set<string> unique(codes.begin(), codes.end());
        return unique.size();
    }
};