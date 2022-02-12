class Solution {
public: 
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        stack<int> stack;   // decreasing monotonic stack
        
        for(int node: arr){
            while(!stack.empty() && stack.top() < node){
                int top = stack.top();
                stack.pop();
                
                ans += (stack.empty() ? top*node : top*min(node, stack.top()));
            }
            stack.push(node);
        }
        
        while(stack.size()>1u){
            int top = stack.top();
            stack.pop();
            
            ans += stack.top()*top;
        }
        
        
        return ans;
    }
};