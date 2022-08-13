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
                if(lastsign == '+'){
                    // stack.push(curr);
                    res += last, last = curr;
                }else if(lastsign == '-'){
                    // stack.push(-curr);
                    res += last, last = -curr;
                }else if(lastsign == '*'){
                    // int top = stack.top();
                    // stack.pop();
                    // stack.push(top*curr);
                    last *= curr;
                }else if(lastsign == '/'){
                    // int top = stack.top();
                    // stack.pop();
                    // stack.push(top/curr);
                    last /= curr;
                }
                lastsign = s[i];
                curr = 0;
            }
        }
        res += last;
        
        // while(!stack.empty())
        //     res += stack.top(), stack.pop();
        return res;
    }
};