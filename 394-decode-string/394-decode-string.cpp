class Solution {
public:
    string helper(string &s, int &i){
        string ans = "";
        while(i < s.size() && s[i] != ']'){
            if(isalpha(s[i])){
                ans += s[i++];
            }
            else if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                
                i++;
                string inner = helper(s, i);
                while(num--)
                    ans += inner;
                i++;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
};