class Solution {
    int helper(string &s, int &ind){
        int ans = 0, sign = 1;
        while(ind < s.size() && s[ind] != ')'){
            if(s[ind] == '+'){
                sign = 1, ind++;
            }else if(s[ind] == '-'){
                sign = -1, ind++;
            }else if(s[ind] == '('){
                ind++;
                ans += sign*helper(s, ind);
                ind++;
            }else if(s[ind] != ' '){
                int num = 0;
                while(ind < s.size() && isdigit(s[ind])){
                    num = 10*num + sign*(s[ind++]-'0');
                }
                ans += num;
            }else{
                ind++;
            }
        }
        return ans;
    }
public:
    int calculate(string s) {
        int ind = 0;
        return helper(s, ind);
    }
};