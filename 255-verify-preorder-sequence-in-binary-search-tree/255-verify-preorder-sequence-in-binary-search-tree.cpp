class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stack;
        int root = INT_MIN;
        for(int x: preorder){
            if(x < root)
                return false;
            while(!stack.empty() && stack.top() < x){
                root = stack.top();
                stack.pop();
            }
            stack.push(x);
        }
        return true;
    }
};