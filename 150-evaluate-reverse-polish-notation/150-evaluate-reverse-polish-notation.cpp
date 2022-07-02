class Solution {
    void findAB(stack<int>& stack, int &a, int &b){
        b = stack.top(); stack.pop();
        a = stack.top(); stack.pop();
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        
        for(auto& token: tokens){
            if(token == "+"){
                int a, b;
                findAB(stack, a, b);
                stack.push(a + b);
            }
            else if(token == "-"){
                int a, b;
                findAB(stack, a, b);
                stack.push(a - b);
            }
            else if(token == "*"){
                int a, b;
                findAB(stack, a, b);
                stack.push(a * b);
            }
            else if(token == "/"){
                int a, b;
                findAB(stack, a, b);
                stack.push(a / b);
            }
            else{
                stack.push(stoi(token));
            }
        }
        
        return stack.top();
    }
};