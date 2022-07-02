class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> map{
            {"+", std::plus<int>()},
            {"-", std::minus<int>()},
            {"*", std::multiplies<int>()},
            {"/", std::divides<int>()}
        };
        
        stack<int> stack;
        
        for(auto& token: tokens){
            if(map.find(token) != map.end()){
                int rhs = stack.top(); stack.pop();
                int lhs = stack.top(); stack.pop();
                stack.push(map[token](lhs, rhs));
            }
            else{
                stack.push(stoi(token));
            }
        }
        
        return stack.top();
    }
};