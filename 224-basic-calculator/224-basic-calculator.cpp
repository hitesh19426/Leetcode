class Solution {
public:
    int helper(int &i, string &s){
        int ans = 0, sign = 1;
        while(i<s.size() && s[i] != ')'){
            if(s[i] == '('){
                i++;
                ans += sign*helper(i, s);
                i++;
            }
            else if(s[i] == '+'){
                sign = 1;
                i++;
            }
            else if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(isdigit(s[i])){
                int num = 0;
                while(i<s.size() && isdigit(s[i]))
                    num = 10*num + (s[i++]-'0');
                ans += sign*num;
            }
            else
                i++;
        }
        return ans;
    }
    
    int calculate(string s) {
        int i = 0;
        return helper(i, s);
    }
};