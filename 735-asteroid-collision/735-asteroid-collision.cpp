class Solution {
public:
    bool sameSign(int a, int b){
        return (a>0 && b>0) || (a<0 && b<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        int ptr = 0;
        
        while(ptr < (int)asteroids.size()){
            if(stack.empty()){
                stack.emplace_back(asteroids[ptr++]);
            }
            else if(sameSign(stack.back(), asteroids[ptr])){
                stack.emplace_back(asteroids[ptr++]);
            }
            else if(stack.back() < 0 && asteroids[ptr]>0){
                stack.emplace_back(asteroids[ptr++]);
            }
            else{
                if(stack.empty()){
                    stack.emplace_back(asteroids[ptr++]);
                }
                else if(stack.back() < -asteroids[ptr]){
                    stack.pop_back();
                }
                else if(stack.back() == -asteroids[ptr]){
                    stack.pop_back(); ptr++;
                }
                else if(stack.back() > -asteroids[ptr]){
                    ptr++;
                }
            }
        }
        
        // stack.resize(stack.empty());
        return stack;
    }
};