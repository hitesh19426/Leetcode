class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(char c: s){
            if(ans.back() + 32 == c || ans.back()-32 == c)
                ans.pop_back();
            else
                ans += c;
        }
        return ans;
    }
};