class Solution {
public:
    int calculate(string s) {
        int res = 0, curr = 0, last = 0;
        char lastsign = '+';
        stack<int> stack;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i]))
                curr = 10*curr + (s[i]-'0');
            if(i == s.size()-1 || (!isdigit(s[i]) && !isspace(s[i]))){
                if(lastsign == '+')
                    res += last, last = curr;
                else if(lastsign == '-')
                    res += last, last = -curr;
                else if(lastsign == '*')
                    last *= curr;
                else if(lastsign == '/')
                    last /= curr;
                lastsign = s[i];
                curr = 0;
            }
        }
        res += last;
        
        return res;
    }
};