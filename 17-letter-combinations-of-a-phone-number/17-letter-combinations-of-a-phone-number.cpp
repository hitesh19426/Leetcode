class Solution {
public:
    vector<string> map{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> helper(string &s, int i){
        if(i < 0)
            return {""};
        
        auto left = helper(s, i-1);
        vector<string> res = {};
        for(auto com: left){
            for(auto c: map[s[i]-'2']){
                res.push_back(com + c);
            }
        }
        
        return res;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        return helper(digits, digits.size()-1);
    }
};