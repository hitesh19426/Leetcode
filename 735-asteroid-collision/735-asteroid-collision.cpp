class Solution {
public:
    bool sameSign(int a, int b){
        return (a>0 && b>0) || (a<0 && b<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        for(int num: asteroids){
            while(num<0 && !stack.empty() && stack.back()>0 && stack.back() < -num){
                stack.pop_back();
            }
            if(!stack.empty() && num < 0 && stack.back() == -num){
                stack.pop_back();
            }
            else if(stack.empty() || sameSign(stack.back(), num) || (num>0 && stack.back() < 0)){
                stack.push_back(num);
            }
        }
        
        return stack;
    }
};